# usr/bin/env python
# -*- coding: utf-8 -*-


class CaesarCipher:
    """Class for doing encryption and decryption using a Caesar cipher."""

    def __init__(self, shift):
        """Constructor Caesar cipher using given integer shift from rotation."""
        encoder = [None] * 26
        decoder = [None] * 26
        for k in range(26):
            encoder[k] = chr((k + shift) % 26 + ord('A'))
            decoder[k] = chr((k - shift) % 26 + ord('A'))
        self._forward = ''.join(encoder)
        self._backward = ''.join(decoder)

    def encrypt(self, msg):
        return self._transform(msg, self._forward)

    def decrypt(self, msg):
        return self._transform(msg, self._backward)

    @staticmethod
    def _transform(original, code):
        """Utility to preform transformation based on given code string."""
        msg = list(original)
        for k in range(len(msg)):
            if msg[k].isupper():
                j = ord(msg[k]) - ord('A')
                msg[k] = code[j]
        return ''.join(msg)


if __name__ == '__main__':
    cipher = CaesarCipher(6)
    message = 'APPLE, MICROSOFT'
    coded = cipher.encrypt(message)
    print('Secret: ', coded)
    answer = cipher.decrypt(coded)
    print('Message: ', answer)
