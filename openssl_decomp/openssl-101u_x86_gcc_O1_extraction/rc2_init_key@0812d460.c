
undefined4 rc2_init_key(EVP_CIPHER_CTX *param_1,uchar *param_2)

{
  int bits;
  int len;
  
                    /* WARNING: Load size is inaccurate */
  bits = *param_1->cipher_data;
  len = EVP_CIPHER_CTX_key_length(param_1);
  RC2_set_key((RC2_KEY *)((int)param_1->cipher_data + 4),len,param_2,bits);
  return 1;
}

