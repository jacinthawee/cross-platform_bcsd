
undefined4 print_attribs(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int iVar6;
  undefined *puVar7;
  undefined *puVar8;
  
  if (param_2 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%s: <No Attributes>\n");
    return 1;
  }
  iVar1 = (*(code *)PTR_sk_num_006a7f2c)(param_2);
  if (iVar1 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%s: <Empty Attributes>\n",param_3);
    return 1;
  }
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%s\n",param_3);
  iVar6 = 0;
  iVar1 = (*(code *)PTR_sk_num_006a7f2c)(param_2);
  if (0 < iVar1) {
    do {
      puVar2 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(param_2,iVar6);
      iVar1 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar2);
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,&DAT_0063d858);
      if (iVar1 == 0) {
        (*(code *)PTR_i2a_ASN1_OBJECT_006a812c)(param_1,*puVar2);
        (*(code *)PTR_BIO_printf_006a7f38)(param_1,": ");
      }
      else {
        uVar4 = (*(code *)PTR_OBJ_nid2ln_006a821c)(iVar1);
        (*(code *)PTR_BIO_printf_006a7f38)(param_1,&DAT_00632848,uVar4);
      }
      iVar1 = (*(code *)PTR_sk_num_006a7f2c)(puVar2[2]);
      if (iVar1 == 0) {
        (*(code *)PTR_BIO_printf_006a7f38)(param_1,"<No Values>\n");
      }
      else {
        piVar3 = (int *)(*(code *)PTR_sk_value_006a7f24)(puVar2[2],0);
        iVar1 = *piVar3;
        if (iVar1 == 4) {
          iVar1 = *(int *)piVar3[1];
          puVar5 = (undefined *)((int *)piVar3[1])[2];
          if (0 < iVar1) {
            puVar7 = puVar5;
            do {
              puVar8 = puVar7 + 1;
              (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%02X ",*puVar7);
              puVar7 = puVar8;
            } while (puVar8 != puVar5 + iVar1);
          }
LAB_0046270c:
          (*(code *)PTR_BIO_printf_006a7f38)(param_1,"\n");
        }
        else if (iVar1 == 0x1e) {
          uVar4 = (*(code *)PTR_OPENSSL_uni2asc_006a8324)
                            (((undefined4 *)piVar3[1])[2],*(undefined4 *)piVar3[1]);
          (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%s\n",uVar4);
          (*(code *)PTR_CRYPTO_free_006a7f88)(uVar4);
        }
        else if (iVar1 == 3) {
          iVar1 = *(int *)piVar3[1];
          puVar5 = (undefined *)((int *)piVar3[1])[2];
          if (iVar1 < 1) goto LAB_0046270c;
          puVar7 = puVar5;
          do {
            puVar8 = puVar7 + 1;
            (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%02X ",*puVar7);
            puVar7 = puVar8;
          } while (puVar5 + iVar1 != puVar8);
          (*(code *)PTR_BIO_printf_006a7f38)(param_1,"\n");
        }
        else {
          (*(code *)PTR_BIO_printf_006a7f38)(param_1,"<Unsupported tag %d>\n");
        }
      }
      iVar6 = iVar6 + 1;
      iVar1 = (*(code *)PTR_sk_num_006a7f2c)(param_2);
    } while (iVar6 < iVar1);
  }
  return 1;
}

