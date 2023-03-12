
undefined4 rc4_init_key(EVP_CIPHER_CTX *param_1,uchar *param_2)

{
  int len;
  
  len = EVP_CIPHER_CTX_key_length(param_1);
  RC4_set_key((RC4_KEY *)param_1->cipher_data,len,param_2);
  return 1;
}

