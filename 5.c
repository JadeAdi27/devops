provider "aws" {
  region = "us-west-2"
}
resource "aws_instance" "ec2_machine" {
  ami           = "ami-07b0c09aab6e66ee9"
  instance_type = "t2.micro"
  # count = 4
  tags = {
    Name = "Terra EC2"
  }
}

--------------------------
  
terraform init
terraform plan
terraform apply

---------------------------

  provider "aws" {
  region = "us-west-2"
}
resource "aws_instance" "ec2_machine" {
  ami           = "ami-07b0c09aab6e66ee9"
  instance_type = "t2.micro"
  count         = 4

  tags = {
    Name = "Terra EC2"
  }
}

resource "aws_s3_bucket" "demo_bucket" {
  bucket = "my-unique-s3-bucket-2025-upload-demo"  # ⚠️ Change this name to something globally unique
  tags = {
    Name = "upload-demo"
  }
}

resource "aws_s3_bucket_object" "text_file" {
  bucket = aws_s3_bucket.demo_bucket.bucket
  key    = "sample1.txt"
  source = "./sample1.txt"
}
