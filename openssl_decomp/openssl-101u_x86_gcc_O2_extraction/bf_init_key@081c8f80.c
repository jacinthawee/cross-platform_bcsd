
undefined4 bf_init_key(EVP_CIPHER_CTX *param_1,uchar *param_2)

{
  int len;
  
  len = EVP_CIPHER_CTX_key_length(param_1);
  BF_set_key((BF_KEY *)param_1->cipher_data,len,param_2);
  return 1;
}

