
void print_qualifiers(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int **ppiVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  ASN1_INTEGER *aint;
  int *piVar7;
  int iVar8;
  char *local_2c;
  
  iVar8 = 0;
  local_2c = "";
  iVar1 = (*(code *)PTR_sk_num_006a6e2c)(param_2);
  if (0 < iVar1) {
    do {
      puVar2 = (undefined4 *)(*(code *)PTR_sk_value_006a6e24)(param_2,iVar8);
      iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar2);
      if (iVar1 == 0xa4) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (param_1,"%*sCPS: %s\n",param_3,"",*(undefined4 *)(puVar2[1] + 8));
      }
      else if (iVar1 == 0xa5) {
        (*(code *)PTR_BIO_printf_006a6e38)(param_1,"%*sUser Notice:\n",param_3,"");
        iVar1 = param_3 + 2;
        ppiVar3 = (int **)puVar2[1];
        piVar7 = *ppiVar3;
        if (piVar7 != (int *)0x0) {
          (*(code *)PTR_BIO_printf_006a6e38)
                    (param_1,"%*sOrganization: %s\n",iVar1,"",*(undefined4 *)(*piVar7 + 8));
          iVar4 = (*(code *)PTR_sk_num_006a6e2c)(piVar7[1]);
          pcVar5 = local_2c;
          if (1 < iVar4) {
            pcVar5 = "s";
          }
          (*(code *)PTR_BIO_printf_006a6e38)(param_1,"%*sNumber%s: ",iVar1,"",pcVar5);
          for (iVar4 = 0; iVar6 = (*(code *)PTR_sk_num_006a6e2c)(piVar7[1]), iVar4 < iVar6;
              iVar4 = iVar4 + 1) {
            aint = (ASN1_INTEGER *)(*(code *)PTR_sk_value_006a6e24)(piVar7[1],iVar4);
            if (iVar4 != 0) {
              (*(code *)PTR_BIO_puts_006a6f58)(param_1,", ");
            }
            pcVar5 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,aint);
            (*(code *)PTR_BIO_puts_006a6f58)(param_1,pcVar5);
            (*(code *)PTR_CRYPTO_free_006a6e88)(pcVar5);
          }
          (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n");
        }
        piVar7 = ppiVar3[1];
        if (piVar7 != (int *)0x0) {
          (*(code *)PTR_BIO_printf_006a6e38)(param_1,"%*sExplicit Text: %s\n",iVar1,"",piVar7[2]);
        }
      }
      else {
        (*(code *)PTR_BIO_printf_006a6e38)(param_1,"%*sUnknown Qualifier: ",param_3 + 2,"");
        (*(code *)PTR_i2a_ASN1_OBJECT_006a702c)(param_1,*puVar2);
        (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n");
      }
      iVar8 = iVar8 + 1;
      iVar1 = (*(code *)PTR_sk_num_006a6e2c)(param_2);
    } while (iVar8 < iVar1);
  }
  return;
}

