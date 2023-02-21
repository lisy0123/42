from setuptools import setup, find_packages

setup(
	name='ai42',
	version='1.0.0',
	author='sanlee',
	author_email='sanlee@student.42.us.org',
	description='Create a package in python',
	url='None',
	packages=find_packages(where='src'),
	packages_dir={'': 'src'},
	license='MIT',
	python_requires= '>=3.7'
)
