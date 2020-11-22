from phe import paillier
public_key, private_key = paillier.generate_paillier_keypair()
secret_nums = [1, 2, 3, 4, 5]
encrypt_nums = [public_key.encrypt(x) for x in secret_nums]   # objects
print(encrypt_nums)
decrypt_nums = [private_key.decrypt(x) for x in encrypt_nums] # original numbers
print(decrypt_nums)



a, b, c, *other = encrypt_nums
a_plus_b = a + b
a_mul_4 = 4 * a
print(private_key.decrypt(a_plus_b))
print(private_key.decrypt(a_mul_4))
