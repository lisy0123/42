import csv


class CsvReader():
	def __init__(self, filename = None, sep = ',',
			header = False, skip_top = 0, skip_bottom = 0):
		if not(isinstance(filename, str) and isinstance(sep, str) and \
				isinstance(header, bool) and isinstance(skip_top, int) and \
				isinstance(skip_bottom, int)):
			exit("Wrong given arguments")

		self.filename = filename
		self.sep = sep
		self.is_header = header
		self.header = None
		self.skip_top = header + skip_top
		self.skip_bottom = skip_bottom
		self.data = []
		self.fd = None

	def __enter__(self):
		try:
			self.fd = open(self.filename, 'r')
			csv_reader = csv.reader(self.fd, delimiter=self.sep)
		except:
			return(None)
		expected_len = None
		for i, row in enumerate(csv_reader):
			if i == 0 and self.is_header is True:
				self.header = row
			elif i >= self.skip_top and (i < self.skip_bottom or self.skip_bottom == 0):
				self.data.append(row)
			if any([(len(element) == 0) for element in row]):
				return(None)
			if expected_len is None:
				expected_len = len(row)
			elif expected_len != len(row):
				return(None)
		return(self)

	def __exit__(self, type, value, trackback):
		if self.fd is not None:
			self.fd.close()

	def getdata(self):
		return(self.data)

	def getheader(self):
		return(self.header)


if __name__ == "__main__":
	def testReader(filename, sep, header, skip_top, skip_bottom):
		with CsvReader(filename, sep, header, skip_top, skip_bottom) as reader:
			if reader == None:
				print("File is corrupted or missing!")
			else:
				print('Header:', reader.getheader(), end = "\n")
				print('Data  :', reader.getdata(), end = "\n\n")

	testReader('good.csv', ',', False, 2, 4)
	testReader('good.csv', ',', True, 0, 5)
	testReader('bad.csv', ',', False, 10, 2)
	testReader('bad.csv', ',', True, 10, 0)
