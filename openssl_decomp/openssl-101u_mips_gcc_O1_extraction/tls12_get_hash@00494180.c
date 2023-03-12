
undefined4 tls12_get_hash(undefined param_1)

{
  undefined4 uVar1;
  
  switch(param_1) {
  default:
    return 0;
  case 2:
                    /* WARNING: Could not recover jumptable at 0x004941c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)PTR_EVP_sha1_006a75d0)();
    return uVar1;
  case 3:
                    /* WARNING: Could not recover jumptable at 0x004941cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)PTR_EVP_sha224_006a81d8)();
    return uVar1;
  case 4:
                    /* WARNING: Could not recover jumptable at 0x004941d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)PTR_EVP_sha256_006a8000)();
    return uVar1;
  case 5:
                    /* WARNING: Could not recover jumptable at 0x004941e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)PTR_EVP_sha384_006a81dc)();
    return uVar1;
  case 6:
                    /* WARNING: Could not recover jumptable at 0x004941b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (*(code *)PTR_EVP_sha512_006a81d4)();
    return uVar1;
  }
}

