
def factorial(n)
	array = [*1..n]	
	return array.inject(1, :*)
end

combination = -> (n) do
    -> (r) do
        return factorial(n)/(factorial(n-r)*factorial(r))
    end
end

n = gets.to_i
r = gets.to_i
nCr = combination.(n)
puts nCr.(r)
