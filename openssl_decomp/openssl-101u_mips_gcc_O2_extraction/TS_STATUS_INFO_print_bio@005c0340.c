
undefined4 TS_STATUS_INFO_print_bio(undefined4 param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  
  (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Status: ");
  uVar1 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)(*param_2);
  if (uVar1 < 6) {
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"%s\n",*(undefined4 *)(status_map_14122 + uVar1 * 4))
    ;
  }
  else {
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"out of bounds\n");
  }
  (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Status description: ");
  for (iVar5 = 0; iVar3 = (*(code *)PTR_sk_num_006a6e2c)(param_2[1]), iVar5 < iVar3;
      iVar5 = iVar5 + 1) {
    if (0 < iVar5) {
      (*(code *)PTR_BIO_puts_006a6f58)(param_1,&DAT_006729ac);
    }
    uVar2 = (*(code *)PTR_sk_value_006a6e24)(param_2[1],iVar5);
    (*(code *)PTR_ASN1_STRING_print_ex_006a9444)(param_1,uVar2,0);
    (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n");
  }
  if (iVar5 == 0) {
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"unspecified\n");
  }
  (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Failure info: ");
  iVar5 = param_2[2];
  if ((iVar5 != 0) && (-1 < failure_map_14123._0_4_)) {
    puVar6 = failure_map_14123;
    iVar3 = 0;
    do {
      iVar4 = (*(code *)PTR_ASN1_BIT_STRING_get_bit_006a9068)(iVar5);
      if (iVar4 != 0) {
        iVar3 = iVar3 + 1;
        if (iVar3 != 1) {
          (*(code *)PTR_BIO_printf_006a6e38)(param_1,", ");
        }
        (*(code *)PTR_BIO_printf_006a6e38)(param_1,"%s",*(int *)((int)puVar6 + 4));
      }
      puVar6 = (undefined1 *)((int)puVar6 + 8);
    } while (-1 < *(int *)puVar6);
    if (iVar3 != 0) goto LAB_005c052c;
  }
  (*(code *)PTR_BIO_printf_006a6e38)(param_1,"unspecified");
LAB_005c052c:
  (*(code *)PTR_BIO_printf_006a6e38)(param_1,"\n");
  return 1;
}

