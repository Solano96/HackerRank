def group_by_marks(marks, pass_marks)

    return marks.group_by {|key, value| 
	            if value < pass_marks
	                "Failed"
	            else
	                "Passed"
	            end
        	} 

end

marks = {"Ramesh":23, "Vivek":40, "Harsh":88, "Mohammad":60}
print group_by_marks(marks, 50)