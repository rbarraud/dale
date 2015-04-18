#!/usr/bin/perl

use warnings;
use strict;
$ENV{"DALE_TEST_ARGS"} ||= "";
my $test_dir = $ENV{"DALE_TEST_DIR"} || ".";
$ENV{PATH} .= ":.";

use Data::Dumper;
use Test::More tests => 3;

my @res = `dalec $ENV{"DALE_TEST_ARGS"} $test_dir/t/src/include.dt -o include-prog`;
is(@res, 0, 'No compilation errors');

@res = `./include-prog`;
is($?, 0, 'Program executed successfully');

chomp for @res;

is_deeply(\@res, [ 'Included file properly' ], 'Got expected results');

`rm include-prog`;

1;