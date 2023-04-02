import requests
import sys

def get_pokemon_data(pokemon_name):
    url = f"https://pokeapi.co/api/v2/pokemon/{pokemon_name}"
    response = requests.get(url)

    if response.status_code == 404:
        return None
    else:
        return response.json()

def print_pokemon_data(pokemon_data, pokemon_name):
    print(f"Name: {pokemon_name}")
    abilities = pokemon_data["abilities"]
    print("Abilities:")
    for ability in abilities:
        print(f"- {ability['ability']['name']}")

def is_number(value):
    try:
        int(value)
        return True
    except ValueError:
        return False

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: python3 pokemon.py <pokemon_name>")
        sys.exit(1)

    input_value = input_value = sys.argv[1].lower()

    if is_number(input_value):
        print("Please provide a pokemon name, not a number.")
        sys.exit(1)

    pokemon_data = get_pokemon_data(input_value)

    if pokemon_data is None:
        print("Invalid pokemon name")
    else:
        print_pokemon_data(pokemon_data, input_value)
