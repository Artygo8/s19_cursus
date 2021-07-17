from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
import pandas as pd
from node import Node
from copy import copy


class DecisionTreeClassifier:

    def __init__(self, criterion='gini', max_depth=10):
        """
        :param str criterion: 'gini' or 'entropy'
        :param max_depth: max_depth of the tree (Decision tree creation
        stops splitting a node if node.depth >= max_depth)
        """
        self.root = Node(split_feature=2, split_kind='<=',
                         split_criteria=1.9, is_leaf=True)

    def fit(self, X, y):
        """
        Build the decision tree from the training set (X, y). The training
        set has m data_points (examples).
        Each of them has n features.
        :param pandas.Dataframe X: Training input (m x n)
        :param pandas.Dataframe y: Labels (m x 1)
        :return object self: Trained tree
        """
        self.root.data = X
        self.root.y = y
        origin = self.root
        if (self.root.split_kind == '<='):
            for elem in X[self.root.split_feature]:
                self.root = origin
                while self.root.is_leaf == False:
                    if elem <= self.root.split_criteria:
                        self.root = self.root.left_child
                    else:
                        self.root = self.root.right_child
                if self.root.split_criteria == '<=':
                    self.root.is_leaf = False
                    if elem <= self.root.split_criteria:
                        self.root.left_child = Node(data=X, labels=y, is_leaf=True, split_feature=self.root.split_feature, split_kind=self.root.split_kind, split_criteria=elem,
                                                    left=None, right=None, depth=self.root.depth + 1)
                    else:
                        self.root.right_child = Node(data=X, labels=y, is_leaf=True, split_feature=self.root.split_feature, split_kind=self.root.split_kind, split_criteria=elem,
                                                     left=None, right=None, depth=self.root.depth + 1)
        print(self.root.left_child)
        print(self.root.right_child)
        return (origin)


if __name__ == '__main__':
    # sklearn is not allowed in the classes.
    # Test on iris dataset
    iris = load_iris()
    X = pd.DataFrame(iris.data)
    y = pd.DataFrame(iris.target)
    X_train, X_test, y_train, y_test = train_test_split(
        X, y, train_size=0.7, random_state=1)
    dec_tree = DecisionTreeClassifier()
    dec_tree.fit(X_train, y_train)
    root = dec_tree.root
    print("TEST ON IRIS DATASET")
    print("Root split info = 'Feature_{}{}{}'\n".format(
        root.split_feature, root.split_kind, root.split_criteria))
    print("5 first lines of the labels of the left child of root      =\n{}\n".format(
        root.left_child.y.head()))
    print("5 first lines of the labels of the right child of root      =\n{}".format(
        root.right_child.y.head()))
