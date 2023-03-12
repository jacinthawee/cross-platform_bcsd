
int X509_certificate_type(X509 *x,EVP_PKEY *pubkey)

{
  int iVar1;
  EVP_PKEY *pkey;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int in_GS_OFFSET;
  uint local_34;
  uint local_30;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if ((x == (X509 *)0x0) ||
     ((pkey = pubkey, pubkey == (EVP_PKEY *)0x0 &&
      (pkey = X509_get_pubkey(x), pkey == (EVP_PKEY *)0x0)))) {
    uVar2 = 0;
    goto LAB_08164ce1;
  }
  iVar1 = pkey->type;
  if (iVar1 == 0x74) {
    uVar3 = 0x412;
    local_34 = 0x212;
    local_30 = 0x112;
    uVar4 = 0x12;
  }
  else if (iVar1 < 0x75) {
    if (iVar1 == 6) {
      uVar3 = 0x431;
      local_34 = 0x231;
      local_30 = 0x131;
      uVar4 = 0x31;
    }
    else if (iVar1 == 0x1c) {
      uVar3 = 0x444;
      local_34 = 0x244;
      local_30 = 0x144;
      uVar4 = 0x44;
    }
    else {
LAB_08164d00:
      uVar3 = 0x400;
      local_34 = 0x200;
      local_30 = 0x100;
      uVar4 = 0;
    }
  }
  else if (iVar1 == 0x198) {
    uVar3 = 0x458;
    local_34 = 600;
    local_30 = 0x158;
    uVar4 = 0x58;
  }
  else {
    if ((iVar1 < 0x198) || (1 < iVar1 - 0x32bU)) goto LAB_08164d00;
    uVar3 = 0x450;
    local_34 = 0x250;
    local_30 = 0x150;
    uVar4 = 0x50;
  }
  local_24 = OBJ_obj2nid(x->sig_alg->algorithm);
  uVar2 = uVar4;
  if (((local_24 != 0) && (iVar1 = OBJ_find_sigid_algs(local_24,(int *)0x0,&local_24), iVar1 != 0))
     && (uVar2 = local_34, local_24 != 0x43)) {
    if (local_24 < 0x44) {
      if ((local_24 == 6) || (uVar2 = uVar4, local_24 == 0x13)) {
        uVar2 = local_30;
      }
    }
    else {
      uVar2 = local_34;
      if ((local_24 != 0x74) && (uVar2 = uVar4, local_24 == 0x198)) {
        uVar2 = uVar3;
      }
    }
  }
  iVar1 = EVP_PKEY_size(pkey);
  if (iVar1 == 0x80 || SCARRY4(iVar1,-0x80) != iVar1 + -0x80 < 0) {
    uVar2 = uVar2 | 0x1000;
  }
  if (pubkey == (EVP_PKEY *)0x0) {
    EVP_PKEY_free(pkey);
  }
LAB_08164ce1:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar2;
}

