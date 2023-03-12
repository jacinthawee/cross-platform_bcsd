
bool int_update(int param_1,uchar *param_2,size_t param_3)

{
  int iVar1;
  
  iVar1 = HMAC_Update((HMAC_CTX *)(*(int *)(*(int *)(param_1 + 0x10) + 0x14) + 0x14),param_2,param_3
                     );
  return iVar1 != 0;
}

