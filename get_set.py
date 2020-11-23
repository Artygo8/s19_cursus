from os import listdir

"""
Utility script to append the getters and setters for all private variables in the
.hpp files, inside the corresponding .cpp file.
"""

def underscores_to_caps(s): 
    """
This function returns a version of the initial string where the `_' are
changed to uppercases.
example: birthday_date >> BirthdayDate
    """
    new_s = ""
    next_is_cap = True
    for i in s:
        if i == '_':
            next_is_cap = True
        elif i == '.':
            break
        else:
            new_s += (i, i.upper())[int(next_is_cap)]
            next_is_cap = False
    return (new_s)


def setter_cpp(class_name, _type, name):
    return f"""

{'void':<12}{class_name}::set{underscores_to_caps(name)}( {_type} new_value ) {{ this->{name} = new_value; }}
"""

def getter_cpp(class_name, _type, name):
    return f"""
{_type:<12}{class_name}::get{underscores_to_caps(name)}( void ) const {{ return this->{name}; }}

"""

def setter_hpp(class_name, _type, name):
    return f"""\t{'void':<16}set{underscores_to_caps(name)}( {_type} new_value );
"""

def getter_hpp(class_name, _type, name):
    return f"""\t{_type:<16}get{underscores_to_caps(name)}( void ) const;
"""

def gen_set_get(hpp_content, hpp=True):
    for i, line in enumerate(hpp_content):
        if "private" in line:
            break
    for line in hpp_content[i:]:
        if '};' in line:
            break
        class_name = underscores_to_caps(fname)
        new_line = line.strip(';\n')
        if len(new_line.split()) == 2:
            _type, name = new_line.split()
            if hpp == True:
                yield(setter_hpp(class_name, _type, name))
                yield(getter_hpp(class_name, _type, name))                
            if hpp == False:
                yield("\n// set and get for " + name.upper())
                yield(setter_cpp(class_name, _type, name))
                yield(getter_cpp(class_name, _type, name))
        else:
            continue

# Starts Here
for fname in listdir("."):
    if ".hpp" in fname:
        
        f = open(fname, "r")
        content = [i for i in f.readlines()]
        f.close()

        setters_and_getters_cpp = [sg for sg in gen_set_get(content, hpp=False)]
        setters_and_getters_hpp = [sg for sg in gen_set_get(content, hpp=True)]

        for i, line in enumerate(content):
            if "private" in line:
                content.insert(i - 1, "\n\t// setters and getters\n")
                for stuff in [sg for sg in setters_and_getters_hpp]:
                    i += 1
                    content.insert(i - 1, stuff)
                break

        with open(fname, 'w') as f_hpp:
            for line in content:
                f_hpp.write(line)

        with open(fname[:-3] + "cpp", 'a') as f_cpp:
            f_cpp.writelines(setters_and_getters_cpp)
