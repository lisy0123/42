WARNING = [
	"\n- Wrong format: ",
	"Vector have to be list / int / tuple.", 
	"Size has to be positive.",
	"Many elements in tuple.",
	"Only int type in tuple.",
	"Ranges need to be in the correct order.",
	"Only float type in list.",
]


WARN = [
	"With two vectors / vector and int.",
	"Vectors have to be same dimension.",
	"Addition: ",
	"Subtraction: ",
	"Division: Only with float / int",
	"Division: Cannot divide with 0.",
	"Multiplication: ",
	"Dot product: Only with two vectors.",
]


EXAMPLE = [
	"\n- Tuple format: (int, int)",
	"\n- List format: [float, float...] or [[float, ...], [float, ...]]",
	"\n-Vector shape: (m, n) and (m, n) / (m, n) and (m, 1) / (m, n) and (1, n)",
	"\n-Vector shape: (1, m) and (m, 1)",
]


EXAMPLE_TEST = [
	"\n- Tuple format: ",
	r"\(int, int\)",
	"\n- List format: ",
	r"\[float, float...\] or \[\[float, ...\], \[float, ...\]\]",
	"\n-Vector shape: ",
	r"\(m, n\) and \(m, n\) / \(m, n\) and \(m, 1\) / \(m, n\) and \(1, n\)",
	r"\(1, m\) and \(m, 1\)",
]


class Op:
	@staticmethod
	def func_add(a: float, b: float) -> float:
		return(a + b)
	@staticmethod
	def func_sub(a: float, b: float) -> float:
		return(a - b)
	@staticmethod
	def func_div(a: float, b: float) -> float:
		return(a / b)
	@staticmethod
	def func_mul(a: float, b: float) -> float:
		return(a * b)


DIC_OP = {
	"add": Op.func_add, "sub": Op.func_sub, 
	"div": Op.func_div, "mul": Op.func_mul
}

DIC_WARN_NUM = {"add": 2, "sub": 3, "mul": 6}
