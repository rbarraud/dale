#!/usr/bin/perl

use warnings;
use strict;
$ENV{"DALE_TEST_ARGS"} ||= "";
my $test_dir = $ENV{"DALE_TEST_DIR"} || ".";
$ENV{PATH} .= ":.";

use Data::Dumper;
use Test::More tests => 3;

my @res = `dalec $ENV{"DALE_TEST_ARGS"} -lm $test_dir/t/src/variant-types.dt -o variant-types`;
is(@res, 0, 'No compilation errors');

@res = `./variant-types`;
is($?, 0, 'Program executed successfully');

chomp for @res;

is_deeply(\@res, [
    'Left (expected) 1',
    'Right (expected) 2',
], 'Got expected results');

`rm variant-types`;

1;
