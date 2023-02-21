def ft_map(function_to_apply, list_of_inputs):
	if callable(function_to_apply):
		if hasattr(list_of_inputs, '__iter__'):
			for element in list_of_inputs:
				yield(function_to_apply(element))
		else:
			input_type = str(type(list_of_inputs)).split("'")[1]
			raise TypeError(f"'{input_type}' object is not iterable")
	else:
		input_type = str(type(function_to_apply)).split("'")[1]
		raise TypeError(f"'{input_type}' object is not callable")
