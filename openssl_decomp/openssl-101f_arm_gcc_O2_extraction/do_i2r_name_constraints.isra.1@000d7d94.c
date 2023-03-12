
undefined4
do_i2r_name_constraints_isra_1(_STACK *param_1,BIO *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  GENERAL_NAME **ppGVar3;
  GENERAL_NAME *gen;
  stack_st_X509_NAME_ENTRY *psVar4;
  BUF_MEM *pBVar5;
  int iVar6;
  
  iVar1 = sk_num(param_1);
  if (0 < iVar1) {
    BIO_printf(param_2,"%*s%s:\n",param_3,"",param_4);
  }
  iVar1 = 0;
  do {
    iVar2 = sk_num(param_1);
    if (iVar2 <= iVar1) {
      return 1;
    }
    ppGVar3 = (GENERAL_NAME **)sk_value(param_1,iVar1);
    BIO_printf(param_2,"%*s",param_3 + 2,"");
    gen = *ppGVar3;
    if (gen->type == 7) {
      psVar4 = ((gen->d).directoryName)->entries;
      pBVar5 = ((gen->d).directoryName)->bytes;
      BIO_puts(param_2,"IP:");
      if (psVar4 == (stack_st_X509_NAME_ENTRY *)0x8) {
        BIO_printf(param_2,"%d.%d.%d.%d/%d.%d.%d.%d",(uint)*(byte *)&pBVar5->length,
                   (uint)*(byte *)((int)&pBVar5->length + 1),
                   (uint)*(byte *)((int)&pBVar5->length + 2),
                   (uint)*(byte *)((int)&pBVar5->length + 3),(uint)*(byte *)&pBVar5->data,
                   (uint)*(byte *)((int)&pBVar5->data + 1),(uint)*(byte *)((int)&pBVar5->data + 2),
                   (uint)*(byte *)((int)&pBVar5->data + 3));
      }
      else {
        if (psVar4 == (stack_st_X509_NAME_ENTRY *)0x20) {
          iVar6 = 1;
          iVar2 = 0;
          do {
            BIO_printf(param_2,"%X",
                       (uint)CONCAT11(*(undefined *)&pBVar5->length,
                                      *(undefined *)((int)&pBVar5->length + 1)));
            if (iVar2 == 7) {
              BIO_puts(param_2,"/");
            }
            else if ((iVar2 == 0xf) || (BIO_puts(param_2,":"), iVar6 == 0x10)) goto LAB_000d7dd0;
            iVar2 = iVar2 + 1;
            iVar6 = iVar6 + 1;
            pBVar5 = (BUF_MEM *)((int)&pBVar5->length + 2);
          } while( true );
        }
        BIO_printf(param_2,"IP Address:<invalid>");
      }
    }
    else {
      GENERAL_NAME_print(param_2,gen);
    }
LAB_000d7dd0:
    iVar1 = iVar1 + 1;
    BIO_puts(param_2,"\n");
  } while( true );
}

