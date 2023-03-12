
int * v2i_NAME_CONSTRAINTS(X509V3_EXT_METHOD *param_1,BIO *param_2,BIO *param_3,char *param_4)

{
  size_t *psVar1;
  undefined *puVar2;
  int *piVar3;
  BIO *pBVar4;
  GENERAL_NAME *pGVar5;
  int iVar6;
  int iVar7;
  GENERAL_NAME **ppGVar8;
  undefined1 *puVar9;
  BIO *pBVar10;
  int iVar11;
  BUF_MEM *pBVar12;
  int iVar13;
  stack_st_X509_NAME_ENTRY *psVar14;
  int *piVar15;
  CONF_VALUE CStack_38;
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  puVar9 = (undefined1 *)param_2;
  pBVar10 = param_3;
  piVar3 = (int *)(*(code *)PTR_ASN1_item_new_006a9778)(NAME_CONSTRAINTS_it);
  if (piVar3 == (int *)0x0) {
    pBVar10 = (BIO *)&DAT_00000041;
    param_4 = "v3_ncons.c";
    puVar9 = (undefined1 *)0x93;
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x93,0x41,"v3_ncons.c",0x98);
    piVar3 = (int *)0x0;
  }
  else {
    for (iVar11 = 0; iVar6 = (*(code *)PTR_sk_num_006a7f2c)(param_3), iVar11 < iVar6;
        iVar11 = iVar11 + 1) {
      iVar6 = (*(code *)PTR_sk_value_006a7f24)(param_3,iVar11);
      iVar13 = *(int *)(iVar6 + 4);
      iVar7 = (*(code *)PTR_strncmp_006aaa7c)(iVar13,"permitted",9);
      if ((iVar7 != 0) || (*(char *)(iVar13 + 9) == '\0')) {
        iVar7 = (*(code *)PTR_strncmp_006aaa7c)(iVar13,"excluded",8);
        if ((iVar7 == 0) && (*(char *)(iVar13 + 8) != '\0')) {
          CStack_38.name = (char *)(iVar13 + 9);
          piVar15 = piVar3 + 1;
          goto LAB_00599bd4;
        }
        pBVar10 = (BIO *)0x8f;
        param_4 = "v3_ncons.c";
        pBVar4 = (BIO *)0x0;
        (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x93,0x8f,"v3_ncons.c",0x87);
LAB_00599cec:
        puVar9 = NAME_CONSTRAINTS_it;
        (*(code *)PTR_ASN1_item_free_006a977c)(piVar3);
        if (pBVar4 == (BIO *)0x0) {
LAB_00599dd8:
          piVar3 = (int *)0x0;
        }
        else {
LAB_00599d08:
          puVar9 = GENERAL_SUBTREE_it;
          (*(code *)PTR_ASN1_item_free_006a977c)(pBVar4);
          piVar3 = (int *)0x0;
        }
        break;
      }
      CStack_38.name = (char *)(iVar13 + 10);
      piVar15 = piVar3;
LAB_00599bd4:
      CStack_38.value = *(char **)(iVar6 + 8);
      pBVar4 = (BIO *)(*(code *)PTR_ASN1_item_new_006a9778)(GENERAL_SUBTREE_it);
      param_4 = (char *)&CStack_38;
      pBVar10 = param_2;
      pGVar5 = v2i_GENERAL_NAME_ex((GENERAL_NAME *)pBVar4->method,param_1,(X509V3_CTX *)param_2,
                                   (CONF_VALUE *)param_4,1);
      if (pGVar5 == (GENERAL_NAME *)0x0) goto LAB_00599cec;
      puVar9 = (undefined1 *)pBVar4;
      if (*piVar15 != 0) {
        iVar6 = (*(code *)PTR_sk_push_006a80a8)();
        if (iVar6 != 0) goto LAB_00599c38;
LAB_00599d94:
        pBVar10 = (BIO *)&DAT_00000041;
        param_4 = "v3_ncons.c";
        (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x93,0x41,"v3_ncons.c",0x98);
        puVar9 = NAME_CONSTRAINTS_it;
        (*(code *)PTR_ASN1_item_free_006a977c)(piVar3);
        if (pBVar4 != (BIO *)0x0) goto LAB_00599d08;
        goto LAB_00599dd8;
      }
      iVar6 = (*(code *)PTR_sk_new_null_006a80a4)();
      *piVar15 = iVar6;
      if ((iVar6 == 0) || (iVar6 = (*(code *)PTR_sk_push_006a80a8)(iVar6), iVar6 == 0))
      goto LAB_00599d94;
LAB_00599c38:
    }
  }
  if (local_2c != *(int *)puVar2) {
    iVar11 = local_2c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    iVar6 = (*(code *)PTR_sk_num_006a7f2c)();
    if (0 < iVar6) {
      (*(code *)PTR_BIO_printf_006a7f38)(puVar9,"%*s%s:\n",pBVar10,"",param_4);
    }
    for (iVar6 = 0; iVar7 = (*(code *)PTR_sk_num_006a7f2c)(iVar11), iVar6 < iVar7; iVar6 = iVar6 + 1
        ) {
      ppGVar8 = (GENERAL_NAME **)(*(code *)PTR_sk_value_006a7f24)(iVar11,iVar6);
      (*(code *)PTR_BIO_printf_006a7f38)
                (puVar9,&DAT_0066dfa4,(undefined *)((int)&pBVar10->method + 2),"");
      pGVar5 = *ppGVar8;
      if (pGVar5->type == 7) {
        psVar14 = ((pGVar5->d).directoryName)->entries;
        pBVar12 = ((pGVar5->d).directoryName)->bytes;
        (*(code *)PTR_BIO_puts_006a8058)(puVar9,&DAT_0066f5a0);
        if (psVar14 == (stack_st_X509_NAME_ENTRY *)0x8) {
          (*(code *)PTR_BIO_printf_006a7f38)
                    (puVar9,"%d.%d.%d.%d/%d.%d.%d.%d",*(undefined *)&pBVar12->length,
                     *(undefined *)((int)&pBVar12->length + 1),
                     *(undefined *)((int)&pBVar12->length + 2),
                     *(undefined *)((int)&pBVar12->length + 3),*(undefined *)&pBVar12->data,
                     *(undefined *)((int)&pBVar12->data + 1),*(undefined *)((int)&pBVar12->data + 2)
                     ,*(undefined *)((int)&pBVar12->data + 3));
        }
        else if (psVar14 == (stack_st_X509_NAME_ENTRY *)0x20) {
          iVar13 = 1;
          iVar7 = 0;
          while( true ) {
            while( true ) {
              psVar1 = &pBVar12->length;
              pBVar12 = (BUF_MEM *)((int)&pBVar12->length + 2);
              (*(code *)PTR_BIO_printf_006a7f38)(puVar9,&DAT_0066ecd4,*(undefined2 *)psVar1);
              if (iVar7 != 7) break;
              iVar7 = 8;
              iVar13 = iVar13 + 1;
              (*(code *)PTR_BIO_puts_006a8058)(puVar9,&DAT_0063ba98);
            }
            if ((iVar7 == 0xf) || ((*(code *)PTR_BIO_puts_006a8058)(puVar9,":"), iVar13 == 0x10))
            break;
            iVar7 = iVar7 + 1;
            iVar13 = iVar13 + 1;
          }
        }
        else {
          (*(code *)PTR_BIO_printf_006a7f38)(puVar9,"IP Address:<invalid>");
        }
      }
      else {
        GENERAL_NAME_print((BIO *)puVar9,pGVar5);
      }
      (*(code *)PTR_BIO_puts_006a8058)(puVar9,"\n");
    }
    return (int *)0x1;
  }
  return piVar3;
}

