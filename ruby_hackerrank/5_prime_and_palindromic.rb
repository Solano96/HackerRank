require 'prime'

def is_palindromic(n)
	return n == n.to_s.reverse.to_i
end

prime_and_palindromic = -> (array_size) do 
    2.upto(Float::INFINITY).lazy.select { |x| x.prime? and is_palindromic(x)}.first(array_size)
end

n = gets.to_i

print prime_and_palindromic.(n)

