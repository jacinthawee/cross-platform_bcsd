
int X509_certificate_type(X509 *x,EVP_PKEY *pubkey)

{
  int iVar1;
  EVP_PKEY *pkey;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_GS_OFFSET;
  int local_34;
  int local_30;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((x == (X509 *)0x0) ||
     ((pkey = pubkey, pubkey == (EVP_PKEY *)0x0 &&
      (pkey = X509_get_pubkey(x), pkey == (EVP_PKEY *)0x0)))) {
    iVar2 = 0;
    goto LAB_08162d9a;
  }
  iVar2 = pkey->type;
  if (iVar2 == 0x74) {
    iVar4 = 0x412;
    local_34 = 0x212;
    local_30 = 0x112;
    iVar3 = 0x12;
  }
  else if (iVar2 < 0x75) {
    if (iVar2 == 6) {
      iVar4 = 0x431;
      local_34 = 0x231;
      local_30 = 0x131;
      iVar3 = 0x31;
    }
    else if (iVar2 == 0x1c) {
      iVar4 = 0x444;
      local_34 = 0x244;
      local_30 = 0x144;
      iVar3 = 0x44;
    }
    else {
LAB_08162db8:
      iVar4 = 0x400;
      local_34 = 0x200;
      local_30 = 0x100;
      iVar3 = 0;
    }
  }
  else if (iVar2 == 0x198) {
    iVar4 = 0x458;
    local_34 = 600;
    local_30 = 0x158;
    iVar3 = 0x58;
  }
  else {
    if ((iVar2 < 0x198) || (1 < iVar2 - 0x32bU)) goto LAB_08162db8;
    iVar4 = 0x450;
    local_34 = 0x250;
    local_30 = 0x150;
    iVar3 = 0x50;
  }
  local_24 = OBJ_obj2nid(x->sig_alg->algorithm);
  iVar2 = iVar3;
  if (((local_24 != 0) && (iVar1 = OBJ_find_sigid_algs(local_24,(int *)0x0,&local_24), iVar1 != 0))
     && (iVar2 = local_34, local_24 != 0x43)) {
    if (local_24 < 0x44) {
      if ((local_24 == 6) || (iVar2 = iVar3, local_24 == 0x13)) {
        iVar2 = local_30;
      }
    }
    else {
      iVar2 = local_34;
      if ((local_24 != 0x74) && (iVar2 = iVar3, local_24 == 0x198)) {
        iVar2 = iVar4;
      }
    }
  }
  if (pubkey == (EVP_PKEY *)0x0) {
    EVP_PKEY_free(pkey);
  }
LAB_08162d9a:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
}

