
int * v2i_NAME_CONSTRAINTS(X509V3_EXT_METHOD *param_1,BIO *param_2,BIO *param_3,char *param_4)

{
  size_t *psVar1;
  undefined *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  BIO *pBVar6;
  GENERAL_NAME **ppGVar7;
  undefined1 *out;
  GENERAL_NAME *pGVar8;
  BIO *pBVar9;
  int iVar10;
  BUF_MEM *pBVar11;
  int iVar12;
  stack_st_X509_NAME_ENTRY *psVar13;
  int *piVar14;
  CONF_VALUE CStack_38;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  out = (undefined1 *)param_2;
  pBVar9 = param_3;
  piVar3 = (int *)(*(code *)PTR_ASN1_item_new_006a8654)(NAME_CONSTRAINTS_it);
  if (piVar3 == (int *)0x0) {
    pBVar9 = (BIO *)&DAT_00000041;
    param_4 = "v3_ncons.c";
    out = (undefined1 *)0x93;
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x93,0x41,"v3_ncons.c",0x95);
    piVar3 = (int *)0x0;
  }
  else {
    for (iVar12 = 0; iVar4 = (*(code *)PTR_sk_num_006a6e2c)(param_3), iVar12 < iVar4;
        iVar12 = iVar12 + 1) {
      iVar4 = (*(code *)PTR_sk_value_006a6e24)(param_3,iVar12);
      iVar10 = *(int *)(iVar4 + 4);
      iVar5 = (*(code *)PTR_strncmp_006a9970)(iVar10,"permitted",9);
      if ((iVar5 != 0) || (*(char *)(iVar10 + 9) == '\0')) {
        iVar5 = (*(code *)PTR_strncmp_006a9970)(iVar10,"excluded",8);
        if ((iVar5 == 0) && (*(char *)(iVar10 + 8) != '\0')) {
          CStack_38.value = *(char **)(iVar4 + 8);
          CStack_38.name = (char *)(iVar10 + 9);
          pBVar6 = (BIO *)(*(code *)PTR_ASN1_item_new_006a8654)(GENERAL_SUBTREE_it);
          piVar14 = piVar3 + 1;
          if (pBVar6 != (BIO *)0x0) goto LAB_00596ea0;
LAB_00596f8c:
          pBVar9 = (BIO *)&DAT_00000041;
          param_4 = "v3_ncons.c";
          (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x93,0x41,"v3_ncons.c",0x95);
LAB_00596fb4:
          out = NAME_CONSTRAINTS_it;
          (*(code *)PTR_ASN1_item_free_006a8658)(piVar3);
          if (pBVar6 != (BIO *)0x0) {
            out = GENERAL_SUBTREE_it;
            (*(code *)PTR_ASN1_item_free_006a8658)(pBVar6);
            piVar3 = (int *)0x0;
            break;
          }
        }
        else {
          pBVar9 = (BIO *)0x8f;
          param_4 = "v3_ncons.c";
          (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x93,0x8f,"v3_ncons.c",0x82);
          out = NAME_CONSTRAINTS_it;
          (*(code *)PTR_ASN1_item_free_006a8658)(piVar3);
        }
        piVar3 = (int *)0x0;
        break;
      }
      CStack_38.value = *(char **)(iVar4 + 8);
      CStack_38.name = (char *)(iVar10 + 10);
      pBVar6 = (BIO *)(*(code *)PTR_ASN1_item_new_006a8654)(GENERAL_SUBTREE_it);
      piVar14 = piVar3;
      if (pBVar6 == (BIO *)0x0) goto LAB_00596f8c;
LAB_00596ea0:
      param_4 = (char *)&CStack_38;
      pBVar9 = param_2;
      pGVar8 = v2i_GENERAL_NAME_ex((GENERAL_NAME *)pBVar6->method,param_1,(X509V3_CTX *)param_2,
                                   (CONF_VALUE *)param_4,1);
      if (pGVar8 == (GENERAL_NAME *)0x0) goto LAB_00596fb4;
      iVar4 = *piVar14;
      if (iVar4 == 0) {
        iVar4 = (*(code *)PTR_sk_new_null_006a6fa4)();
        *piVar14 = iVar4;
        if (iVar4 == 0) goto LAB_00596f8c;
      }
      out = (undefined1 *)pBVar6;
      iVar4 = (*(code *)PTR_sk_push_006a6fa8)(iVar4);
      if (iVar4 == 0) goto LAB_00596f8c;
    }
  }
  if (local_2c == *(int *)puVar2) {
    return piVar3;
  }
  iVar12 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar4 = (*(code *)PTR_sk_num_006a6e2c)();
  if (0 < iVar4) {
    (*(code *)PTR_BIO_printf_006a6e38)(out,"%*s%s:\n",pBVar9,"",param_4);
  }
  for (iVar4 = 0; iVar5 = (*(code *)PTR_sk_num_006a6e2c)(iVar12), iVar4 < iVar5; iVar4 = iVar4 + 1)
  {
    ppGVar7 = (GENERAL_NAME **)(*(code *)PTR_sk_value_006a6e24)(iVar12,iVar4);
    (*(code *)PTR_BIO_printf_006a6e38)(out,&DAT_0066d674,(undefined *)((int)&pBVar9->method + 2),"")
    ;
    pGVar8 = *ppGVar7;
    if (pGVar8->type == 7) {
      psVar13 = ((pGVar8->d).directoryName)->entries;
      pBVar11 = ((pGVar8->d).directoryName)->bytes;
      (*(code *)PTR_BIO_puts_006a6f58)(out,&DAT_0066ec70);
      if (psVar13 == (stack_st_X509_NAME_ENTRY *)0x8) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (out,"%d.%d.%d.%d/%d.%d.%d.%d",*(undefined *)&pBVar11->length,
                   *(undefined *)((int)&pBVar11->length + 1),
                   *(undefined *)((int)&pBVar11->length + 2),
                   *(undefined *)((int)&pBVar11->length + 3),*(undefined *)&pBVar11->data,
                   *(undefined *)((int)&pBVar11->data + 1),*(undefined *)((int)&pBVar11->data + 2),
                   *(undefined *)((int)&pBVar11->data + 3));
      }
      else if (psVar13 == (stack_st_X509_NAME_ENTRY *)0x20) {
        iVar10 = 1;
        iVar5 = 0;
        while( true ) {
          while( true ) {
            psVar1 = &pBVar11->length;
            pBVar11 = (BUF_MEM *)((int)&pBVar11->length + 2);
            (*(code *)PTR_BIO_printf_006a6e38)(out,&DAT_0066e3a4,*(undefined2 *)psVar1);
            if (iVar5 != 7) break;
            iVar5 = 8;
            iVar10 = iVar10 + 1;
            (*(code *)PTR_BIO_puts_006a6f58)(out,&DAT_0063b2b4);
          }
          if ((iVar5 == 0xf) || ((*(code *)PTR_BIO_puts_006a6f58)(out,":"), iVar10 == 0x10)) break;
          iVar5 = iVar5 + 1;
          iVar10 = iVar10 + 1;
        }
      }
      else {
        (*(code *)PTR_BIO_printf_006a6e38)(out,"IP Address:<invalid>");
      }
    }
    else {
      GENERAL_NAME_print((BIO *)out,pGVar8);
    }
    (*(code *)PTR_BIO_puts_006a6f58)(out,"\n");
  }
  return (int *)0x1;
}

