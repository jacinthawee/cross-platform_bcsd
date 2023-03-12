
undefined4 rc4_init_key(EVP_CIPHER_CTX *param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  
  pvVar2 = param_1->cipher_data;
  iVar1 = EVP_CIPHER_CTX_key_length(param_1);
  (*(code *)PTR_RC4_set_key_006a8aec)(pvVar2,iVar1,param_2);
  return 1;
}

