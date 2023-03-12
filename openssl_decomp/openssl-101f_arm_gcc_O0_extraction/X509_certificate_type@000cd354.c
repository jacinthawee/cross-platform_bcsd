
int X509_certificate_type(X509 *x,EVP_PKEY *pubkey)

{
  EVP_PKEY *pkey;
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int local_24;
  
  if (x == (X509 *)0x0) {
    return 0;
  }
  pkey = pubkey;
  if ((pubkey == (EVP_PKEY *)0x0) && (pkey = X509_get_pubkey(x), pkey == (EVP_PKEY *)0x0)) {
    return 0;
  }
  iVar1 = pkey->type;
  if (iVar1 == 0x74) {
    uVar3 = 0x412;
    uVar4 = 0x212;
    uVar5 = 0x112;
    uVar2 = 0x12;
  }
  else if (iVar1 < 0x75) {
    if (iVar1 == 6) {
      uVar3 = 0x431;
      uVar4 = 0x231;
      uVar5 = 0x131;
      uVar2 = 0x31;
    }
    else if (iVar1 == 0x1c) {
      uVar3 = 0x444;
      uVar4 = 0x244;
      uVar5 = 0x144;
      uVar2 = 0x44;
    }
    else {
LAB_000cd3cc:
      uVar3 = 0x400;
      uVar4 = 0x200;
      uVar5 = 0x100;
      uVar2 = 0;
    }
  }
  else if (iVar1 == 0x198) {
    uVar3 = 0x458;
    uVar4 = 600;
    uVar5 = 0x158;
    uVar2 = 0x58;
  }
  else {
    if ((iVar1 < 0x198) || (1 < iVar1 - 0x32bU)) goto LAB_000cd3cc;
    uVar3 = 0x450;
    uVar4 = 0x250;
    uVar5 = 0x150;
    uVar2 = 0x50;
  }
  local_24 = OBJ_obj2nid(x->sig_alg->algorithm);
  if ((local_24 == 0) || (iVar1 = OBJ_find_sigid_algs(local_24,(int *)0x0,&local_24), iVar1 == 0))
  goto LAB_000cd3b2;
  if (local_24 != 0x43) {
    if (local_24 < 0x44) {
      if ((local_24 == 6) || (local_24 == 0x13)) {
        uVar2 = uVar5;
      }
      goto LAB_000cd3b2;
    }
    if (local_24 == 0x198) {
      uVar2 = uVar3;
    }
    if (local_24 != 0x74) goto LAB_000cd3b2;
  }
  uVar2 = uVar4;
LAB_000cd3b2:
  iVar1 = EVP_PKEY_size(pkey);
  if (iVar1 < 0x81) {
    uVar2 = uVar2 | 0x1000;
  }
  if (pubkey == (EVP_PKEY *)0x0) {
    EVP_PKEY_free(pkey);
  }
  return uVar2;
}

