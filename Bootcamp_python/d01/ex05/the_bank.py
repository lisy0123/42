class Account(object):
	ID_COUNT = 1

	def __init__(self, name, **kwargs):
		self.id = self.ID_COUNT
		self.name = name
		self.__dict__.update(kwargs)
		Account.ID_COUNT += 1
		
	def transfer(self, amount):
		self.value += amount

	def __str__(self):
		name = self.name if hasattr(self, 'name') else None
		id = self.id if hasattr(self, 'id') else None
		value = self.value if hasattr(self, 'value') else None
		return(f"Account[ name: {name}, id: {id}, value: {value} ]")

	def __repr__(self):
		return(f"Account: [ {self.__dict__} ]")


class Bank(object):
	"""The bank"""""
	def __init__(self):
		self.account = []


	def add(self, account):
		self.account.append(account)


	def is_corrupted(self, account) -> bool:
		if not isinstance(account, Account):
			return(True)
		acc_attr = dir(account)
		if len(acc_attr) % 2 == 0 or \
			'name' not in acc_attr or \
			'id' not in acc_attr or \
			'value' not in acc_attr or \
			len(list(filter(lambda attr: attr.startswith('b'), acc_attr))) != 0 or \
			len(list(filter(lambda attr: attr.startswith('zip'), acc_attr))) == 0 or \
			len(list(filter(lambda attr: attr.startswith('addr'), acc_attr))) == 0:	
			return(True)
		return(False)


	def get_account(self, person) -> Account or None:
		if not isinstance(person, (int, str)):
			return(None)

		def filter_with_id(account: Account) -> bool:
			return((account.id == person) if hasattr(account, 'id') else False)

		def filter_with_name(account: Account) -> bool:
			return((account.name == person) if hasattr(account, 'name') else False)

		func_filter = filter_with_id if isinstance(person, int) else filter_with_name
		account = next(filter(func_filter, self.account), None)
		return(account)

	
	def account_check(self, origin, dest, amount):
		check = True
		origin_account = self.get_account(origin)
		dest_account = self.get_account(dest)
		
		if self.is_corrupted(origin_account) or origin_account.value < amount:
			check = False
		if self.is_corrupted(dest_account):
			check = False
		return(origin_account, dest_account, check)
		

	def transfer(self, origin, dest, amount) -> bool:
		"""
			@origin:  int(id) or str(name) of the first account
			@dest:    int(id) or str(name) of the destination account
			@amount:  float(amount) amount to transfer
			@return         True if success, False if an error occured
		"""
		if not isinstance(amount, float) or not isinstance(origin, (int, str)) or \
			not isinstance(dest, (int, str)) or amount < 0:
			return(False)
		origin_account, dest_account, check = self.account_check(origin, dest, amount)
		if check:
			origin_account.transfer(-amount)
			dest_account.transfer(amount)
		return(check)


	def fix_account(self, account) -> bool:
		"""
			fix the corrupted account
			@account: int(id) or str(name) of the account
			@return         True if success, False if an error occured
		"""
		if not isinstance(account, (int, str)):
			return(False)
		acc = self.get_account(account)
		if not isinstance(acc, Account):
			return(False)

		if self.is_corrupted(acc):
			acc_attr = dir(acc)
			dic_attr = ['name', 'id', 'value']
			for attr in dic_attr:
				if attr not in acc_attr:
					if attr == 'value':
						setattr(acc, attr, 0)
					else:
						setattr(acc, attr, None)
			b_attr = list(filter(lambda attr: attr.startswith('b'), acc_attr))
			if len(b_attr) != 0:
				for b_attr_name in b_attr:
					delattr(b_attr, b_attr_name)
			zip_attr = list(filter(lambda attr: attr.startswith('zip'), acc_attr))
			if len(zip_attr) == 0:
				setattr(acc, 'zip', None)
			addr_attr = list(filter(lambda attr: attr.startswith('addr'), acc_attr))
			if len(addr_attr) == 0:
				setattr(acc, 'addr', None)
			if len(dir(acc)) % 2 == 0:
				setattr(acc, f'ex{len(dir(acc))}', None)
		return(True)
