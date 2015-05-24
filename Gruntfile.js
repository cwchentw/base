/**
 * Created by cwchen on 5/24/15.
 */
module.exports = function (grunt) {
    grunt.initConfig({
        bats : {
            files: ['test/test.sh']
        }
    })

    grunt.loadNpmTasks('grunt-bats');

    grunt.registerTask('test', ['bats']);
};