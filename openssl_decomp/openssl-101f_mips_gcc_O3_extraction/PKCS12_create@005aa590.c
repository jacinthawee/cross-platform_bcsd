
PKCS12 * PKCS12_create(char *pass,char *name,EVP_PKEY *pkey,X509 *cert,stack_st_X509 *ca,int nid_key
                      ,int nid_cert,int iter,int mac_iter,int keytype)

{
  undefined *puVar1;
  stack_st_PKCS12_SAFEBAG *psVar2;
  X509 *pXVar3;
  int iVar4;
  undefined4 uVar5;
  char *name_00;
  uchar *name_01;
  PKCS7 *p12;
  PKCS7 *unaff_s1;
  PKCS7 *pPVar6;
  X509 *unaff_s2;
  stack_st_PKCS12_SAFEBAG *local_7c;
  int local_78;
  int local_74;
  int local_70;
  uchar auStack_6c [64];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (nid_cert == 0) {
    nid_cert = 0x95;
  }
  if (nid_key == 0) {
    nid_key = 0x92;
  }
  local_7c = (stack_st_PKCS12_SAFEBAG *)0x0;
  local_78 = 0;
  if (iter == 0) {
    iter = 0x800;
  }
  if (mac_iter == 0) {
    mac_iter = 1;
  }
  if (pkey == (EVP_PKEY *)0x0) {
    if (cert != (X509 *)0x0) goto LAB_005aa67c;
    if (ca == (stack_st_X509 *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(0x23,0x69,0x68,"p12_crt.c",0x6e);
      p12 = (PKCS7 *)0x0;
      pPVar6 = unaff_s1;
      goto LAB_005aa7d4;
    }
  }
  else if (cert != (X509 *)0x0) {
    iVar4 = (*(code *)PTR_X509_check_private_key_006a817c)(cert,pkey);
    if (iVar4 == 0) goto LAB_005aa8e4;
    uVar5 = (*(code *)PTR_EVP_sha1_006a86c4)();
    (*(code *)PTR_X509_digest_006a87e0)(cert,uVar5,auStack_6c,&local_78);
LAB_005aa67c:
    cert = (X509 *)PKCS12_add_cert(&local_7c,cert);
    if (((name != (char *)0x0) &&
        (iVar4 = PKCS12_add_friendlyname_asc((PKCS12_SAFEBAG *)cert,name,-1), iVar4 == 0)) ||
       ((local_78 != 0 &&
        (iVar4 = PKCS12_add_localkeyid((PKCS12_SAFEBAG *)cert,auStack_6c,local_78), iVar4 == 0))))
    goto LAB_005aa7b0;
  }
  cert = (X509 *)0x0;
  iVar4 = (*(code *)PTR_sk_num_006a7f2c)(ca);
  if (0 < iVar4) {
    do {
      unaff_s2 = (X509 *)(*(code *)PTR_sk_value_006a7f24)(ca,cert);
      local_74 = -1;
      local_70 = -1;
      unaff_s1 = (PKCS7 *)PKCS12_x5092certbag(unaff_s2);
      if (unaff_s1 == (PKCS7 *)0x0) goto LAB_005aa7b0;
      name_00 = (char *)(*(code *)PTR_X509_alias_get0_006a87fc)(unaff_s2,&local_74);
      if (((name_00 != (char *)0x0) &&
          (iVar4 = PKCS12_add_friendlyname_asc((PKCS12_SAFEBAG *)unaff_s1,name_00,local_74),
          iVar4 == 0)) ||
         ((name_01 = (uchar *)(*(code *)PTR_X509_keyid_get0_006aa314)(unaff_s2,&local_70),
          name_01 != (uchar *)0x0 &&
          (iVar4 = PKCS12_add_localkeyid((PKCS12_SAFEBAG *)unaff_s1,name_01,local_70), iVar4 == 0)))
         ) {
LAB_005aa7a0:
        PKCS12_SAFEBAG_free((PKCS12_SAFEBAG *)unaff_s1);
        goto LAB_005aa7b0;
      }
      if (local_7c == (stack_st_PKCS12_SAFEBAG *)0x0) {
        local_7c = (stack_st_PKCS12_SAFEBAG *)(*(code *)PTR_sk_new_null_006a80a4)();
        if (local_7c != (stack_st_PKCS12_SAFEBAG *)0x0) {
          iVar4 = (*(code *)PTR_sk_push_006a80a8)(local_7c,unaff_s1);
          if (iVar4 != 0) goto LAB_005aa840;
          (*(code *)PTR_sk_free_006a7f80)(local_7c);
          local_7c = (stack_st_PKCS12_SAFEBAG *)0x0;
        }
        goto LAB_005aa7a0;
      }
      iVar4 = (*(code *)PTR_sk_push_006a80a8)(local_7c,unaff_s1);
      if (iVar4 == 0) goto LAB_005aa7a0;
LAB_005aa840:
      cert = (X509 *)((int)&cert->cert_info + 1);
      iVar4 = (*(code *)PTR_sk_num_006a7f2c)(ca);
    } while ((int)cert < iVar4);
  }
  psVar2 = local_7c;
  if (local_7c == (stack_st_PKCS12_SAFEBAG *)0x0) {
    cert = (X509 *)0x0;
  }
  else {
    cert = (X509 *)(*(code *)PTR_sk_new_null_006a80a4)();
    if (cert == (X509 *)0x0) goto LAB_005aa7b0;
    if (nid_cert == -1) {
      unaff_s1 = PKCS12_pack_p7data(psVar2);
    }
    else {
      unaff_s1 = PKCS12_pack_p7encdata(nid_cert,pass,-1,(uchar *)0x0,0,iter,psVar2);
    }
    if (unaff_s1 == (PKCS7 *)0x0) {
      (*(code *)PTR_sk_free_006a7f80)(cert);
      goto LAB_005aa7b0;
    }
    iVar4 = (*(code *)PTR_sk_push_006a80a8)(cert,unaff_s1);
    if (iVar4 == 0) {
      (*(code *)PTR_sk_free_006a7f80)(cert);
      PKCS7_free(unaff_s1);
      if (local_7c != (stack_st_PKCS12_SAFEBAG *)0x0) goto LAB_005aa7bc;
LAB_005aa8e4:
      p12 = (PKCS7 *)0x0;
      pPVar6 = unaff_s1;
      goto LAB_005aa7d4;
    }
  }
  (*(code *)PTR_sk_pop_free_006a8158)(local_7c,PTR_PKCS12_SAFEBAG_free_006a834c);
  local_7c = (stack_st_PKCS12_SAFEBAG *)0x0;
  pXVar3 = cert;
  if (pkey == (EVP_PKEY *)0x0) goto LAB_005aab28;
  unaff_s1 = (PKCS7 *)PKCS12_add_key(&local_7c,pkey,keytype,iter,nid_key,pass);
  if (unaff_s1 == (PKCS7 *)0x0) goto LAB_005aab04;
  iVar4 = (*(code *)PTR_EVP_PKEY_get_attr_by_NID_006aa330)(pkey,0x1a1,0xffffffff);
  if (-1 < iVar4) {
    uVar5 = (*(code *)PTR_EVP_PKEY_get_attr_006aa334)(pkey,iVar4);
    iVar4 = (*(code *)PTR_X509at_add1_attr_006a9d80)(&unaff_s1->state,uVar5);
    if (iVar4 == 0) goto LAB_005aab04;
  }
  iVar4 = (*(code *)PTR_EVP_PKEY_get_attr_by_NID_006aa330)(pkey,0x358,0xffffffff);
  if (-1 < iVar4) {
    uVar5 = (*(code *)PTR_EVP_PKEY_get_attr_006aa334)(pkey,iVar4);
    iVar4 = (*(code *)PTR_X509at_add1_attr_006a9d80)(&unaff_s1->state,uVar5);
    if (iVar4 == 0) goto LAB_005aab04;
  }
  if ((name != (char *)0x0) &&
     (iVar4 = PKCS12_add_friendlyname_asc((PKCS12_SAFEBAG *)unaff_s1,name,-1), iVar4 == 0))
  goto LAB_005aab04;
  if ((local_78 != 0) &&
     (iVar4 = PKCS12_add_localkeyid((PKCS12_SAFEBAG *)unaff_s1,auStack_6c,local_78), iVar4 == 0))
  goto LAB_005aab04;
  psVar2 = local_7c;
  if (local_7c == (stack_st_PKCS12_SAFEBAG *)0x0) goto LAB_005aab28;
  if (cert != (X509 *)0x0) {
    unaff_s1 = PKCS12_pack_p7data(local_7c);
    if (unaff_s1 == (PKCS7 *)0x0) goto LAB_005aab04;
    iVar4 = (*(code *)PTR_sk_push_006a80a8)(cert,unaff_s1);
    if (iVar4 != 0) goto LAB_005aab28;
    goto LAB_005aaaf4;
  }
  unaff_s2 = (X509 *)(*(code *)PTR_sk_new_null_006a80a4)();
  if (unaff_s2 != (X509 *)0x0) {
    unaff_s1 = PKCS12_pack_p7data(psVar2);
    pPVar6 = unaff_s1;
    if (unaff_s1 != (PKCS7 *)0x0) goto LAB_005aac6c;
    (*(code *)PTR_sk_free_006a7f80)(unaff_s2);
  }
LAB_005aa7b0:
  do {
    p12 = (PKCS7 *)0x0;
    pPVar6 = unaff_s1;
    if (local_7c != (stack_st_PKCS12_SAFEBAG *)0x0) {
LAB_005aa7bc:
      (*(code *)PTR_sk_pop_free_006a8158)(local_7c,PTR_PKCS12_SAFEBAG_free_006a834c);
      p12 = (PKCS7 *)0x0;
      pPVar6 = unaff_s1;
    }
LAB_005aa7d4:
    if (local_2c == *(int *)puVar1) {
      return (PKCS12 *)p12;
    }
    unaff_s1 = (PKCS7 *)(*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005aac6c:
    iVar4 = (*(code *)PTR_sk_push_006a80a8)(unaff_s2,unaff_s1);
    pXVar3 = unaff_s2;
    if (iVar4 != 0) {
LAB_005aab28:
      cert = pXVar3;
      (*(code *)PTR_sk_pop_free_006a8158)(local_7c,PTR_PKCS12_SAFEBAG_free_006a834c);
      local_7c = (stack_st_PKCS12_SAFEBAG *)0x0;
      p12 = (PKCS7 *)PKCS12_init(0x15);
      unaff_s1 = p12;
      if (p12 == (PKCS7 *)0x0) goto LAB_005aab04;
      iVar4 = PKCS12_pack_authsafes((PKCS12 *)p12,(stack_st_PKCS7 *)cert);
      if (iVar4 == 0) {
        PKCS12_free((PKCS12 *)p12);
        goto LAB_005aab04;
      }
      (*(code *)PTR_sk_pop_free_006a8158)(cert,PTR_PKCS7_free_006a8350);
      pPVar6 = p12;
      if ((mac_iter == -1) ||
         (iVar4 = PKCS12_set_mac((PKCS12 *)p12,pass,-1,(uchar *)0x0,0,mac_iter,(EVP_MD *)0x0),
         iVar4 != 0)) goto LAB_005aa7d4;
      PKCS12_free((PKCS12 *)p12);
      goto LAB_005aa7b0;
    }
    (*(code *)PTR_sk_free_006a7f80)(unaff_s2);
    unaff_s1 = pPVar6;
LAB_005aaaf4:
    PKCS7_free(unaff_s1);
LAB_005aab04:
    if (cert != (X509 *)0x0) {
      (*(code *)PTR_sk_pop_free_006a8158)(cert,PTR_PKCS7_free_006a8350);
    }
  } while( true );
}

