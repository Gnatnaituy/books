from urllib import parse, request

# Base url being accessed
url = 'http:///httpbin.org/get'

# Dictionary for query paramaters( if any )
parms = {
	'name1': 'value1',
	'name2': 'value2'
}

# Encoding the query string
querystring = parse.urlencode(parms)

# Make a GET request and read the response
u = request.urlopen(url, querystring)
resp = u.read()
