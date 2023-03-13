
undefined4 bf_init_key(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 0x60);
  uVar1 = (*(code *)PTR_EVP_CIPHER_CTX_key_length_006a8a00)();
  (*(code *)PTR_BF_set_key_006a7a04)(uVar2,uVar1,param_2);
  return 1;
}

