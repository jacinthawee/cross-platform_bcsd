
undefined4 rc2_init_key(EVP_CIPHER_CTX *param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  
  pvVar2 = param_1->cipher_data;
  iVar1 = EVP_CIPHER_CTX_key_length(param_1);
                    /* WARNING: Load size is inaccurate */
  (*(code *)PTR_RC2_set_key_006a7a00)((int)pvVar2 + 4,iVar1,param_2,*param_1->cipher_data);
  return 1;
}

