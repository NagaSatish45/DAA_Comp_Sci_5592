# DAA_Comp_Sci_5592

Code For Quick,insert and Merge Sorts 
and The analysis based on Time complexity and graphical representation
and documented all the details
using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using Amazon;
using Amazon.CertificateManager;
using Amazon.CertificateManager.Model;

class Program
{
    static async Task Main(string[] args)
    {
        // AWS credentials setup (ensure AWS CLI or credentials file is configured)
        var awsAccessKeyId = "<YourAWSAccessKeyId>";
        var awsSecretAccessKey = "<YourAWSSecretAccessKey>";
        var regionEndpoint = RegionEndpoint.USWest2; // Change to your desired AWS region

        var credentials = new Amazon.Runtime.BasicAWSCredentials(awsAccessKeyId, awsSecretAccessKey);
        var config = new AmazonCertificateManagerConfig
        {
            RegionEndpoint = regionEndpoint
        };

        // Create an ACM client
        using var acmClient = new AmazonCertificateManagerClient(credentials, config);

        // Fetch ACM certificates
        var request = new ListCertificatesRequest();
        var response = await acmClient.ListCertificatesAsync(request);

        Console.WriteLine("AWS Certificates:");
        foreach (var certificateSummary in response.CertificateSummaryList)
        {
            Console.WriteLine($"Certificate ARN: {certificateSummary.CertificateArn}");
            Console.WriteLine($"Certificate Domain: {certificateSummary.DomainName}");
            Console.WriteLine();
        }
    }
}
