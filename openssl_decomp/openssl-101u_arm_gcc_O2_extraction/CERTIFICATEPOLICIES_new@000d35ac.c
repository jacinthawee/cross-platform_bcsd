
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CERTIFICATEPOLICIES * CERTIFICATEPOLICIES_new(void)

{
  CERTIFICATEPOLICIES *pCVar1;
  
  pCVar1 = (CERTIFICATEPOLICIES *)ASN1_item_new((ASN1_ITEM *)PTR_CERTIFICATEPOLICIES_it_000d35b4);
  return pCVar1;
}

