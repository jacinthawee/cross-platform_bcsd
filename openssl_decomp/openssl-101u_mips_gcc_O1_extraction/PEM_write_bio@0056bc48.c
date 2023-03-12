
int PEM_write_bio(BIO *bp,char *name,char *hdr,uchar *data,long len)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int local_a0;
  int local_90;
  undefined auStack_8c [96];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_EVP_EncodeInit_006a8af4)(auStack_8c);
  iVar2 = (*(code *)PTR_strlen_006a9a24)(name);
  iVar3 = (*(code *)PTR_BIO_write_006a6e14)(bp,"-----BEGIN ",0xb);
  if ((((iVar3 == 0xb) && (iVar3 = (*(code *)PTR_BIO_write_006a6e14)(bp,name,iVar2), iVar2 == iVar3)
       ) && (iVar3 = (*(code *)PTR_BIO_write_006a6e14)(bp,"-----\n",6), iVar3 == 6)) &&
     ((iVar3 = (*(code *)PTR_strlen_006a9a24)(hdr), iVar3 < 1 ||
      ((iVar4 = (*(code *)PTR_BIO_write_006a6e14)(bp,hdr,iVar3), iVar3 == iVar4 &&
       (iVar3 = (*(code *)PTR_BIO_write_006a6e14)(bp,"\n",1), iVar3 == 1)))))) {
    iVar3 = (*(code *)PTR_CRYPTO_malloc_006a7008)(0x2000,"pem_lib.c",0x268);
    if (iVar3 == 0) goto LAB_0056bfc4;
    if (len < 1) {
      local_a0 = 0;
    }
    else {
      local_a0 = 0;
      iVar4 = 0;
      do {
        iVar5 = 0x1400;
        if (len < 0x1401) {
          iVar5 = len;
        }
        (*(code *)PTR_EVP_EncodeUpdate_006a8afc)(auStack_8c,iVar3,&local_90,data + iVar4,iVar5);
        if ((local_90 != 0) &&
           (iVar6 = (*(code *)PTR_BIO_write_006a6e14)(bp,iVar3), iVar6 != local_90))
        goto LAB_0056beb8;
        len = len - iVar5;
        local_a0 = local_a0 + local_90;
        iVar4 = iVar4 + iVar5;
      } while (0 < len);
    }
    (*(code *)PTR_EVP_EncodeFinal_006a8b00)(auStack_8c,iVar3,&local_90);
    if ((0 < local_90) && (iVar4 = (*(code *)PTR_BIO_write_006a6e14)(bp,iVar3), iVar4 != local_90))
    {
LAB_0056beb8:
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar3,0x2000);
      (*(code *)PTR_CRYPTO_free_006a6e88)(iVar3);
      uVar7 = 7;
      goto LAB_0056bcf4;
    }
    (*(code *)PTR_OPENSSL_cleanse_006a7074)(iVar3,0x2000);
    (*(code *)PTR_CRYPTO_free_006a6e88)(iVar3);
    iVar3 = (*(code *)PTR_BIO_write_006a6e14)(bp,"-----END ",9);
    if (((iVar3 == 9) && (iVar3 = (*(code *)PTR_BIO_write_006a6e14)(bp,name,iVar2), iVar2 == iVar3))
       && (iVar2 = (*(code *)PTR_BIO_write_006a6e14)(bp,"-----\n",6), iVar2 == 6)) {
      local_a0 = local_a0 + local_90;
      goto LAB_0056bd18;
    }
  }
  uVar7 = 7;
LAB_0056bcf4:
  while( true ) {
    (*(code *)PTR_ERR_put_error_006a7f34)(9,0x72,uVar7,"pem_lib.c",0x288);
    local_a0 = 0;
LAB_0056bd18:
    if (local_2c == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_0056bfc4:
    uVar7 = 0x41;
  }
  return local_a0;
}

