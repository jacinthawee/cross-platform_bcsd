
bool dsa_pub_cmp(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_BN_cmp_006a7960)
                    (*(undefined4 *)(*(int *)(param_2 + 0x14) + 0x18),
                     *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x18),param_3,param_4,&_gp);
  return iVar1 == 0;
}

