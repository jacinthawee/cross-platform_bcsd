
int TS_find_cert_part_0(undefined4 param_1,int *param_2)

{
  int iVar1;
  int **ppiVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  
  iVar5 = 0;
  while( true ) {
    iVar1 = (*(code *)PTR_sk_num_006a6e2c)(param_1);
    if (iVar1 <= iVar5) {
      return -1;
    }
    ppiVar2 = (int **)(*(code *)PTR_sk_value_006a6e24)(param_1,iVar5);
    if (((**ppiVar2 == 0x14) &&
        (iVar1 = (*(code *)PTR_memcmp_006a9ad0)((*ppiVar2)[2],param_2 + 0x14,0x14), iVar1 == 0)) &&
       ((piVar6 = ppiVar2[1], piVar6 == (int *)0x0 ||
        ((((iVar1 = *param_2, iVar1 != 0 &&
           (iVar3 = (*(code *)PTR_sk_num_006a6e2c)(*piVar6), iVar3 == 1)) &&
          (piVar4 = (int *)(*(code *)PTR_sk_value_006a6e24)(*piVar6,0), *piVar4 == 4)) &&
         ((iVar3 = (*(code *)PTR_X509_NAME_cmp_006a8030)(piVar4[1],*(undefined4 *)(iVar1 + 0xc)),
          iVar3 == 0 &&
          (iVar1 = (*(code *)PTR_ASN1_INTEGER_cmp_006a8d38)(piVar6[1],*(undefined4 *)(iVar1 + 4)),
          iVar1 == 0)))))))) break;
    iVar5 = iVar5 + 1;
  }
  return iVar5;
}

