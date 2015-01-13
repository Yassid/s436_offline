#!/usr/bin/perl

use strict;

my @sorted_files = sort { -M $b <=> -M $a } @ARGV;

for (my $i=0;$i<=$#sorted_files;$i++) {
	print $sorted_files[$i]."\n";
}
