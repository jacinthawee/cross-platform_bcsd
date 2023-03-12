
int PEM_write(FILE *fp,char *name,char *hdr,uchar *data,long len)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int unaff_s0;
  char *unaff_s8;
  int local_a0;
  int *local_98;
  int local_90;
  undefined auStack_8c [96];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar2 = (*(code *)PTR_BIO_s_file_006a7fa0)();
  iVar3 = (*(code *)PTR_BIO_new_006a7fa4)(uVar2);
  if (iVar3 == 0) {
    local_a0 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(9,0x71,7,"pem_lib.c",0x248);
    iVar3 = unaff_s0;
    goto LAB_0056f234;
  }
  (*(code *)PTR_BIO_ctrl_006a7f18)(iVar3,0x6a,0,fp);
  (*(code *)PTR_EVP_EncodeInit_006a9c10)(auStack_8c);
  iVar4 = (*(code *)PTR_strlen_006aab30)(name);
  iVar5 = (*(code *)PTR_BIO_write_006a7f14)(iVar3,"-----BEGIN ",0xb);
  if ((((iVar5 == 0xb) &&
       (iVar5 = (*(code *)PTR_BIO_write_006a7f14)(iVar3,name,iVar4), iVar4 == iVar5)) &&
      (iVar5 = (*(code *)PTR_BIO_write_006a7f14)(iVar3,"-----\n",6), iVar5 == 6)) &&
     ((iVar5 = (*(code *)PTR_strlen_006aab30)(hdr), iVar5 < 1 ||
      ((iVar6 = (*(code *)PTR_BIO_write_006a7f14)(iVar3,hdr,iVar5), iVar5 == iVar6 &&
       (iVar5 = (*(code *)PTR_BIO_write_006a7f14)(iVar3,"\n",1), iVar5 == 1)))))) {
    unaff_s8 = "7 datafinal";
    iVar5 = (*(code *)PTR_CRYPTO_malloc_006a8108)(0x2000,"pem_lib.c",0x26a);
    if (iVar5 == 0) goto LAB_0056f51c;
    local_a0 = 0;
    if (0 < len) {
      iVar6 = 0;
      do {
        iVar7 = 0x1400;
        if (len < 0x1401) {
          iVar7 = len;
        }
        (*(code *)PTR_EVP_EncodeUpdate_006a9c18)(auStack_8c,iVar5,&local_90,data + iVar6,iVar7);
        if ((local_90 != 0) &&
           (iVar8 = (*(code *)PTR_BIO_write_006a7f14)(iVar3,iVar5), iVar8 != local_90))
        goto LAB_0056f3d8;
        len = len - iVar7;
        local_a0 = local_a0 + local_90;
        iVar6 = iVar6 + iVar7;
      } while (0 < len);
    }
    local_98 = &local_90;
    (*(code *)PTR_EVP_EncodeFinal_006a9c1c)(auStack_8c,iVar5,local_98);
    if ((0 < local_90) &&
       (iVar6 = (*(code *)PTR_BIO_write_006a7f14)(iVar3,iVar5), iVar6 != local_90)) {
LAB_0056f3d8:
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar5,0x2000);
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar5);
      uVar2 = 7;
      goto LAB_0056f200;
    }
    (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar5,0x2000);
    (*(code *)PTR_CRYPTO_free_006a7f88)(iVar5);
    iVar5 = (*(code *)PTR_BIO_write_006a7f14)(iVar3,"-----END ",9);
    if (((iVar5 == 9) &&
        (iVar5 = (*(code *)PTR_BIO_write_006a7f14)(iVar3,name,iVar4), iVar4 == iVar5)) &&
       (iVar4 = (*(code *)PTR_BIO_write_006a7f14)(iVar3,"-----\n",6), iVar4 == 6)) {
      local_a0 = local_a0 + local_90;
      goto LAB_0056f224;
    }
  }
  unaff_s8 = "7 datafinal";
  uVar2 = 7;
LAB_0056f200:
  while( true ) {
    local_a0 = 0;
    (*(code *)PTR_ERR_put_error_006a9030)(9,0x72,uVar2,unaff_s8 + -0x3850,0x28b);
LAB_0056f224:
    (*(code *)PTR_BIO_free_006a7f70)(iVar3);
LAB_0056f234:
    if (local_2c == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_0056f51c:
    uVar2 = 0x41;
  }
  return local_a0;
}

