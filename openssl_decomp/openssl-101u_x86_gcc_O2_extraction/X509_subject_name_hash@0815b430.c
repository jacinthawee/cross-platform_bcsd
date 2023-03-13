
ulong X509_subject_name_hash(X509 *x)

{
  X509_NAME *a;
  EVP_MD *type;
  int iVar1;
  ulong uVar2;
  int in_GS_OFFSET;
  ulong local_24 [5];
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  a = x->cert_info->subject;
  i2d_X509_NAME(a,(uchar **)0x0);
  type = EVP_sha1();
  iVar1 = EVP_Digest(a->canon_enc,a->canon_enclen,(uchar *)local_24,(uint *)0x0,type,(ENGINE *)0x0);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = local_24[0];
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return uVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

