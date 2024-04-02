import requests
import time

while True:
    user_input = input("Enter a number: ")
    try:
        value = int(user_input)
    except ValueError:
        print("Please enter a valid number.")
        continue

    data = {'value': value}  # Your data here
    response = requests.post('http://127.0.0.1:5000/receive_data', json=data)

    response = requests.get('http://127.0.0.1:5000/get_data')
    data = response.json()
    received_number = data['value']
    print("Received number:", received_number)
    
    print(response.text)
    time.sleep(1)  # Send data every 5 seconds
