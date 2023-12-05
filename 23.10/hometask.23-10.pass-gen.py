import random
import string

def generate_password(length, use_digits=True, use_uppercase=True, use_lowercase=True, use_special_chars=True):
    characters = ""
    
    if use_digits:
        characters += string.digits
    if use_uppercase:
        characters += string.ascii_uppercase
    if use_lowercase:
        characters += string.ascii_lowercase
    if use_special_chars:
        characters += string.punctuation

    if not characters:
        return "Please select at least one character type."

    password = ''.join(random.choice(characters) for _ in range(length))
    return password

def main():
    try:
        length = int(input("Enter the password length: "))
        count = int(input("Enter the number of passwords to generate: "))
        
        use_digits = input("Use digits (0-9)? (y/n): ").lower() == 'y'
        use_uppercase = input("Use uppercase letters (A-Z)? (y/n): ").lower() == 'y'
        use_lowercase = input("Use lowercase letters (a-z)? (y/n): ").lower() == 'y'
        use_special_chars = input("Use special characters (!@#$%, etc.)? (y/n): ").lower() == 'y'

        for _ in range(count):
            password = generate_password(length, use_digits, use_uppercase, use_lowercase, use_special_chars)
            print("Generated password:", password)

    except ValueError:
        print("Please enter valid numbers for length and count.")
    
if __name__ == "__main__":
    main()