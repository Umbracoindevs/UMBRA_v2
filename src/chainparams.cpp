
// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2018-2019 The Umbra 2 developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (1, uint256("0x00000e201a7d9f70df0503d11934e16316cffa13266e8cb9e7fbadc9e954ae3c"))
    (2, uint256("0x00000f09b638159105a52900de64c7980e7eaa22de74d1e44ba563e12a26b0bf"))
    (3, uint256("0x00000d50fb85e159d38f52a2673f8b04747cf2fa40b024cf45f89181ff1a16bb"))
    (4, uint256("0x00000c57ae1aa7a0a369985774312c0b09bb3b2c1e831d0c053e96bc76e7900d"))
    (5, uint256("0x00000cf891fb598d5003beb15e7ccecdd6a27c4a9175c907097dbfb02362b94f"))
    (6, uint256("0x000004bd62a48bdf99ec4e4b807b2027977601ff97a924ac8363e70a25b79245"))
    (7, uint256("0x00000ee82a413c328bffa81b97aa9f36d6b8227297ae65100a991a07d86cb025"))
    (8, uint256("0x00000bdd3fea973a53cacc1d5f220dfd6c6c3828f9628ddc51b26a306156670f"))
    (9, uint256("0x00000a9dca57117a830b7275b4eebb8c236e1d9752608646237c6aadfd768c1b"))
    (10, uint256("0x00000b2b3917f727c8b2058ce82a4cc9e7be33532ed75de86456c04f72bbb082"))
    (11, uint256("0x0000072fd8866e228f9f27477795f012af403eeb97f9dab65e39333084da79f6"))
    (12, uint256("0x0000057b1929392d1d9ec02f3eebe398014c854fa2fae2c64219502aac6eaac0"))
    (13, uint256("0x00000e65563348e7e68320b9a71a841c551a68f34c1d4cfb6912d438cbddff04"))
    (14, uint256("0x0000031074a9915e992ac06122d9d79dc642f267536d974c6319af6be181868f"))
    (15, uint256("0x00000893803191160f3a7b08d065185c6e53b133e72cbb57c270ac88e7995bea"))
    (16, uint256("0x00000cb412a4b03a0ef168ef69f728f3236991e510c1c697a4a19b460e345d60"))
    (17, uint256("0x00000d5f183af5b70f46dc22d00423784f121d8291ceb14d8ff9ed1705a6198d"))
    (18, uint256("0x00000ef20c97e6dedac7c0bcc4c560e6fc463118fd0184c03c0e7c4363206437"))
    (19, uint256("0x000001686f93e70a43abd23010d59e2e941a68aa5762af5c13b5db38035863d5"))
    (20, uint256("0x00000c822f0db2156c9a182fb94312c3bdd655021164cce4469966b672880009"))
    (21, uint256("0x00000c550ae5f0ce9c1cce51ccb559760ec2ac2f3127b21f856924f188983bab"))
    (22, uint256("0x000009b700adc5215bf96af7e34776b7efb211fafd38af47875ff1d45fc0f48c"))
    (23, uint256("0x000003b20df2aa14c604ab4e9b8ce96dc763e6a87d256e2b3382f4777061bae8"))
    (24, uint256("0x0000090cc8a5b0a8294e51adbcb1ea119783e2d5d641f29782a2d0e1a5e2e34a"))
    (25, uint256("0x000006ba78e1369433967db91f3fe76a41b53694f7fe53e25d8b1cea099cf3fc"))
    (26, uint256("0x000006deb067254ff06cc9a7250f54c41b030305f0e43360d4f0d6c658583aff"))
    (27, uint256("0x000001b403dc60b7886926e3572eb3168b3456f376c27f9f580e748fa6a9a08e"))
    (28, uint256("0x00000d021d49e48a69b7dd423a6c2cd6fb6e420a0b30ba8dfea64aa7b8fea4f6"))
    (29, uint256("0x00000a5cc8b72603e5341f0e0168d5a67c0a2b949f4926a28a2514366e654568"))
    (30, uint256("0x00000debcbe4edce98c0ed2abd6fdd3265957219af8c5698abe3da5c9f548a4d"))
    (31, uint256("0x00000a0a6e2d51070a51467e225c15f0cc56adb1e8384afe9b16210b3e793740"))
    (32, uint256("0x000004a70a7ef529128372b35d3123eeb17bfb2063ed40a415f298b7954b5959"))
    (33, uint256("0x00000d7c940e88e3aa2dcba99c3ca15b9f4a07a48d0480b9092eb73c9cef9941"))
    (34, uint256("0x00000c03e192aa6e965a7bfb800f240c988b1f9e7f580f95602a62d96f2a0f02"))
    (35, uint256("0x0000053f6415e06b39f9661a0cff0c74f95732b40e9825bca1a27c13faff8716"))
    (36, uint256("0x000007518504bc82d36c16e0a70192562f4f3a65b1b6415daef8b38e09acfe51"))
    (37, uint256("0x00000a1afa90401f1239144db1792a0a5da1efcede0b32453890c96cb689c506"))
    (38, uint256("0x0000052d719f309c96c35044198d4c6a9e9a3d264709e390499306cfe88c3712"))
    (39, uint256("0x000006b6f0c2ba0dad3044e4f8678bbca2a8b79b990e3ab0457a780247ac88f5"))
    (301, uint256("00000044d5c955c3daa9725522f95c3bae876e6ae7ba652d70a9ee6018584e69e"));
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1546214086, // * UNIX timestamp of last checkpoint block
    301,      // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    1000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1546202840,
    0,
    250};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1545453420,
    0,
    100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params() const
{
    assert(this);
    static CBigNum bnTrustedModulus(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParams = libzerocoin::ZerocoinParams(bnTrustedModulus);

    return &ZCParams;
}

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x3f;
        pchMessageStart[1] = 0x39;
        pchMessageStart[2] = 0xe9;
        pchMessageStart[3] = 0x08;
        vAlertPubKey = ParseHex("044102bad584e559c38ad8be50484b570d77a58251ff078eb2c75e57a9d60966c1e4b1c63df646db583612111fc413a4d8ca327f37525e27b12bde03f56d1d50e2");
        nDefaultPort = 18878;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // Umbra starting difficulty is 1 / 2^12
        nSubsidyHalvingInterval = 99999999;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan = 120;
        nTargetSpacing = 120;
        nMaturity = 30;
        nMasternodeCountDrift = 20;
        nMaxMoneyOut = 25000000 * COIN;

        nLastPOWBlock = 400;
        nModifierUpdateBlock = 999999999;
        nZerocoinStartHeight = 5120000;
        nAccumulatorStartHeight = 1;
        nZerocoinStartTime = 1545453420;
        nBlockEnforceSerialRange = 1;
        nBlockRecalculateAccumulators = ~1;
        nBlockFirstFraudulent = ~1;
        nBlockLastGoodCheckpoint = ~400;
        const char* pszTimestamp = "Elon Musk I want to be clear — I do not respect the SEC Rockets Oranges and David Hasselhoff";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 250 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("044102bad584e559c38ad8be50484b570d77a58251ff078eb2c75e57a9d60966c1e4b1c63df646db583612111fc413a4d8ca327f37525e27b12bde03f56d1d50e2") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1545453420;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 118011;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x983187781fecc3181af6fc5211abbd2feb62e09fadf971970353cf98e6b2fc10"));
        assert(genesis.hashMerkleRoot == uint256("0xe5b9c9a658a89f8a7af6b01443045f7423345fb3ab17dc3436335a98a3fec70b"));

        vSeeds.push_back(CDNSSeedData("207.148.21.185", "207.148.21.185"));
        vSeeds.push_back(CDNSSeedData("45.77.167.240", "45.77.167.240"));
        vSeeds.push_back(CDNSSeedData("149.28.207.68", "149.28.207.68 "));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 68); // U
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 50); // N
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 25); // B
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x2e)(0x21)(0x71).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x08)(0x25)(0x39)(0x2F).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0xbc).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fRequireRPCPassword = false;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKey = "042feb9a8e026467a8316c1f140440af99e4b5fdbb6949eea83e8eae76ab82bc91d63ffb857938aad23d2cc949dbc6bc1ab1661f7501f2ddeddacd307774e6dd50" ;
        strObfuscationPoolDummyAddress = "UX11LPuyMfnEHBW71v7LRraw95SFZLfjQJ";
        nStartMasternodePayments = 1545453420;

        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023527381951378636564391212010397122822120720357";
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * ZCENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 4; //Block headers must be this version once zerocoin is active
        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x35;
        pchMessageStart[1] = 0xc8;
        pchMessageStart[2] = 0x8d;
        pchMessageStart[3] = 0xc5;
        vAlertPubKey = ParseHex("0405b9b540363a2d702bc33095753cf026f27b69600ab7ce0c1fe16da645fd4c662e4dc8dd608b78b6c3130722dd29c3f4e26099b53f36d4a5a902f401bf344ecf");
        nDefaultPort = 88882;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // Umbra: 1 day
        nTargetSpacing = 1 * 60;  // Umbra: 1 minute
        nLastPOWBlock = 50;
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 51197;
        nMaxMoneyOut = 50000000 * COIN;
        nZerocoinStartHeight = 1;
        nZerocoinStartTime = 1545453419;
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 9908000; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 0; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = 0; //Last valid accumulator checkpoint

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1546202840;
        genesis.nNonce = 29;

        hashGenesisBlock = genesis.GetHash();
        //assert(hashGenesisBlock == uint256("0x0cf8ee76af1e7ce3340e88b5ce3fc6d72a8ffa1ed4a274c6731291a3daebae0f"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("127.0.0.1", "127.0.0.1"));
	vSeeds.push_back(CDNSSeedData("127.0.0.1", "127.0.0.1"));


        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet umbra addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet umbra script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet umbra BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet umbra BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet umbra BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fRequireRPCPassword = false;
        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "0405b9b540363a2d702bc33095753cf026f27b69600ab7ce0c1fe16da645fd4c662e4dc8dd608b78b6c3130722dd29c3f4e26099b53f36d4a5a902f401bf344ecf";
        strObfuscationPoolDummyAddress = "xp87cG8UEQgzs1Bk67Yk884C7pnQfAeo7q";
        nStartMasternodePayments = 1545453421; //Fri, 09 Jan 2015 21:05:58 GMT
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0x34;
        pchMessageStart[1] = 0xc4;
        pchMessageStart[2] = 0x92;
        pchMessageStart[3] = 0xb7;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // Umbra: 1 day
        nTargetSpacing = 1 * 60;        // Umbra: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1545453421;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 732084;

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 18880;
        //assert(hashGenesisBlock == uint256("0x000008415bdca132b70cf161ecc548e5d0150fd6634a381ee2e99bb8bb77dbb3"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 18881;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fRequireRPCPassword = false;
        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};

static CChainParams* pCurrentParams = 0;

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
