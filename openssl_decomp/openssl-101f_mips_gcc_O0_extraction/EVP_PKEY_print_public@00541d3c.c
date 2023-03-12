
int EVP_PKEY_print_public(BIO *out,EVP_PKEY *pkey,int indent,ASN1_PCTX *pctx)

{
  int iVar1;
  undefined4 uVar2;
  code *UNRECOVERED_JUMPTABLE;
  
  if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(pkey->ameth + 0x20), UNRECOVERED_JUMPTABLE != (code *)0x0))
  {
                    /* WARNING: Could not recover jumptable at 0x00541d80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)();
    return iVar1;
  }
  (*(code *)PTR_BIO_indent_006a97d0)(out,indent,0x80);
  uVar2 = (*(code *)PTR_OBJ_nid2ln_006a821c)(pkey->type);
  BIO_printf(out,"%s algorithm \"%s\" unsupported\n","Public Key",uVar2);
  return 1;
}
