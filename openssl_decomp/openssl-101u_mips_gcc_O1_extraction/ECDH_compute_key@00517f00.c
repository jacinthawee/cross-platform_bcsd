
int ECDH_compute_key(void *out,size_t outlen,EC_POINT *pub_key,EC_KEY *ecdh,KDF *KDF)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_ecdh_check_006a87b0)(ecdh);
  if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00517f84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(*(int *)(iVar1 + 0xc) + 4))(out,outlen,pub_key,ecdh);
    return iVar1;
  }
  return 0;
}

