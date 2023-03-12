
undefined4
do_i2r_name_constraints_isra_1(undefined4 param_1,BIO *param_2,int param_3,undefined4 param_4)

{
  size_t *psVar1;
  int iVar2;
  int iVar3;
  GENERAL_NAME **ppGVar4;
  GENERAL_NAME *gen;
  BUF_MEM *pBVar5;
  stack_st_X509_NAME_ENTRY *psVar6;
  int iVar7;
  
  iVar2 = (*(code *)PTR_sk_num_006a6e2c)();
  if (0 < iVar2) {
    (*(code *)PTR_BIO_printf_006a6e38)(param_2,"%*s%s:\n",param_3,"",param_4);
  }
  iVar2 = 0;
  do {
    iVar3 = (*(code *)PTR_sk_num_006a6e2c)(param_1);
    if (iVar3 <= iVar2) {
      return 1;
    }
    ppGVar4 = (GENERAL_NAME **)(*(code *)PTR_sk_value_006a6e24)(param_1,iVar2);
    (*(code *)PTR_BIO_printf_006a6e38)(param_2,&DAT_0066d674,param_3 + 2,"");
    gen = *ppGVar4;
    if (gen->type == 7) {
      psVar6 = ((gen->d).directoryName)->entries;
      pBVar5 = ((gen->d).directoryName)->bytes;
      (*(code *)PTR_BIO_puts_006a6f58)(param_2,&DAT_0066ec70);
      if (psVar6 == (stack_st_X509_NAME_ENTRY *)0x8) {
        (*(code *)PTR_BIO_printf_006a6e38)
                  (param_2,"%d.%d.%d.%d/%d.%d.%d.%d",*(undefined *)&pBVar5->length,
                   *(undefined *)((int)&pBVar5->length + 1),*(undefined *)((int)&pBVar5->length + 2)
                   ,*(undefined *)((int)&pBVar5->length + 3),*(undefined *)&pBVar5->data,
                   *(undefined *)((int)&pBVar5->data + 1),*(undefined *)((int)&pBVar5->data + 2),
                   *(undefined *)((int)&pBVar5->data + 3));
      }
      else if (psVar6 == (stack_st_X509_NAME_ENTRY *)0x20) {
        iVar7 = 1;
        iVar3 = 0;
        while( true ) {
          while( true ) {
            psVar1 = &pBVar5->length;
            pBVar5 = (BUF_MEM *)((int)&pBVar5->length + 2);
            (*(code *)PTR_BIO_printf_006a6e38)(param_2,&DAT_0066e3a4,*(undefined2 *)psVar1);
            if (iVar3 != 7) break;
            iVar3 = 8;
            iVar7 = iVar7 + 1;
            (*(code *)PTR_BIO_puts_006a6f58)(param_2,&DAT_0063b2b4);
          }
          if (iVar3 == 0xf) break;
          (*(code *)PTR_BIO_puts_006a6f58)(param_2,":");
          if (iVar7 == 0x10) break;
          iVar3 = iVar3 + 1;
          iVar7 = iVar7 + 1;
        }
      }
      else {
        (*(code *)PTR_BIO_printf_006a6e38)(param_2,"IP Address:<invalid>");
      }
    }
    else {
      GENERAL_NAME_print(param_2,gen);
    }
    iVar2 = iVar2 + 1;
    (*(code *)PTR_BIO_puts_006a6f58)(param_2,"\n");
  } while( true );
}

