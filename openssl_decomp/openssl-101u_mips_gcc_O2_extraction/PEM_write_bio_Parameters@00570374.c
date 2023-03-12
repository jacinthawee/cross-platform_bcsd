
int PEM_write_bio_Parameters(BIO *bp,EVP_PKEY *x)

{
  undefined *puVar1;
  EVP_PKEY_ASN1_METHOD *pEVar2;
  int iVar3;
  undefined4 uVar4;
  BIO *bp_00;
  EVP_PKEY *pEVar5;
  BIO *in_a2;
  EVP_PKEY *in_a3;
  EVP_PKEY aEStack_6c [2];
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  pEVar2 = x->ameth;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if ((pEVar2 == (EVP_PKEY_ASN1_METHOD *)0x0) ||
     (in_a2 = (BIO *)0x670000, *(int *)(pEVar2 + 0x3c) == 0)) {
    bp = in_a2;
    iVar3 = 0;
  }
  else {
    pEVar5 = aEStack_6c;
    (*(code *)PTR_BIO_snprintf_006a6f60)(pEVar5,0x50,"%s PARAMETERS",*(undefined4 *)(pEVar2 + 0xc));
    in_a3 = x;
    iVar3 = PEM_ASN1_write_bio(*(undefined1 **)(x->ameth + 0x3c),(char *)pEVar5,bp,x,
                               (EVP_CIPHER *)0x0,(uchar *)0x0,0,(undefined1 *)0x0,(void *)0x0);
    x = pEVar5;
  }
  if (local_1c == *(int *)puVar1) {
    return iVar3;
  }
  iVar3 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar4 = (*(code *)PTR_BIO_s_file_006a6ea0)();
  bp_00 = (BIO *)(*(code *)PTR_BIO_new_006a6ea4)(uVar4);
  if (bp_00 == (BIO *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(9,0x7c,7,"pem_pkey.c",0xda);
    pEVar5 = (EVP_PKEY *)0x0;
  }
  else {
    (*(code *)PTR_BIO_ctrl_006a6e18)(bp_00,0x6a,0,iVar3);
    pEVar5 = PEM_read_bio_PrivateKey(bp_00,(EVP_PKEY **)x,(undefined1 *)bp,in_a3);
    (*(code *)PTR_BIO_free_006a6e70)(bp_00);
  }
  return (int)pEVar5;
}

