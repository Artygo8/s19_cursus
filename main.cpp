/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossuin <agossuin@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 12:00:01 by agossuin          #+#    #+#             */
/*   Updated: 2020/12/28 12:00:01 by agossuin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// to compile, use the following :
// clang++ -Wall -Wextra -Werror -std=c++98 -I tests -I ft_containers main.cpp tests/*.cpp

#include "test.hpp"

int main() {
    test_list();
    test_vector();
    test_map();
    test_stack();
    test_queue();
    return 0;
}
