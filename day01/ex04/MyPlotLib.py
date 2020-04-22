class MyPlotLib:
    def histogram(self, data, features):
        def histogram(self, data, features):
            fig, axes = plt.subplots(nrow=1, ncol=len(features))
            for ft in features:
                ft = axes.flatten()
                lst = list(data[ft])
                arr = np.array([x for x in lst if ~np.isnan(x)])
                ft.hist(arr, bins=8)
                ft.set_tittle(ft)
                ft.grid()
            plt.show()

    def density(self, data, features):
        pass

    def pair_plot(self, data, features):
        pass

    def box_plot(self, data, features):
        pass


if __name__ == "__main__":
    # kwargs = dict(alpha=0.8, bins=10)
    path = "athlete_events.csv"
    fl = FileLoader()
    df = fl.load(path)

    # x = df['Height']
    # y = df['Weight']

    features = ['Height', 'Weight']
    test = MyPlotLib()
    test.histogram(df, features)
