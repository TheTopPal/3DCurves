# Small Program in C++ Implementing 3D Curves Hierarchy

This project involves designing a small program in C++ that supports a hierarchy of 3D curves. The main focus is on supporting three types of 3D geometric curves: circles, ellipses, and 3D helices. Here are the steps involved:

## Step 1: Define 3D Geometric Curves

Each curve type should be able to return a 3D point and a first derivative (3D vector) per parameter `t` along the curve. The simplified definitions of these curves are as follows:

- **Circle**

- **Ellipse**

- **Helix**

## Step 2: Populate Container with Randomly Created Objects

Create a container (e.g. vector or list) of objects of these types created randomly with random parameters.

## Step 3: Print Coordinates and Derivatives

Print the coordinates of points and derivatives of all curves in the container at `t=PI/4`.

## Step 4: Create Second Container with Only Circles

Populate a second container that contains only circles from the first container. Ensure the second container shares (i.e., not clones) circles of the first one, e.g., via pointers.

## Step 5: Sort the Second Container

Sort the second container in ascending order of circles’ radii. That is, the first element has the smallest radius, the last - the greatest.

## Step 6: Compute Total Sum of Radii

Compute the total sum of radii of all curves in the second container.

## Optional Requirements

* Split the implementation into a library of curves (.dll or .so) and an executable which uses the API of this library. 
