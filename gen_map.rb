width = ARGV[0].to_i
height = ARGV[1].to_i

map = '1' * width
map << "\n"
map << '1'
map << "CEP" + '0' * (width - 5)
map << '1'
map << "\n"
(1..(height - 3)).each do |line|
	l = ''
	l << '1'
	l << '0' * (width - 2)
	l << '1'
	map << l
	map << "\n"
end
map << '1' * width
map << "\n"

puts map