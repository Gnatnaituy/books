import requests

# make a request
r = requests.get('https://api.github.com/events')

print(r) # <Response [200]>
print(r.text)

payload = {'key1': 'value1', 'key2': 'value2'}
x = requests.get('http://httpbin.org/get', params=payload)
print(x)
print(x.url)
