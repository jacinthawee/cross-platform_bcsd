
void exnode_free(byte **param_1)

{
  if ((*param_1 != (byte *)0x0) && ((**param_1 & 8) != 0)) {
    CRYPTO_free(param_1);
    return;
  }
  return;
}

