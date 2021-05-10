{
  mode: 'development',
  resolve: {
    modules: [
      '/home/ilya/pgit/Study/kotlin/web-react/build/js/packages/confexplorer/kotlin-dce-dev',
      'node_modules'
    ]
  },
  plugins: [
    ProgressPlugin {
      profile: false,
      handler: [Function: handler],
      modulesCount: 500,
      showEntries: false,
      showModules: true,
      showActiveModules: true
    },
    TeamCityErrorPlugin {}
  ],
  module: {
    rules: [
      {
        test: /\.js$/,
        use: [
          'source-map-loader'
        ],
        enforce: 'pre'
      },
      {
        test: /\.css$/,
        use: [
          {
            loader: 'style-loader',
            options: {}
          },
          {
            loader: 'css-loader',
            options: {}
          }
        ]
      }
    ]
  },
  entry: {
    main: [
      '/home/ilya/pgit/Study/kotlin/web-react/build/js/packages/confexplorer/kotlin-dce-dev/confexplorer.js'
    ]
  },
  output: {
    path: '/home/ilya/pgit/Study/kotlin/web-react/build/distributions',
    filename: [Function: filename],
    library: 'confexplorer',
    libraryTarget: 'umd',
    globalObject: 'this'
  },
  devtool: 'eval-source-map',
  stats: {
    warningsFilter: [
      /Failed to parse source map/
    ],
    warnings: false,
    errors: false
  }
}